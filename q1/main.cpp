// mac937@nyu.edu
// hw10 question 1

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Checks whether a character is a boundary character.
 * @param ch a character
 * @return true if and only if the character is a letter in the US English alphabet
 */
bool isBoundary(char ch) {
    return isspace(ch) || ispunct(ch);
}

void findBoundaries(const string& sentence, vector<int>& startPositions, vector<int>& lengths) {
    bool inWord = false;
    int wordLength = 0;
    for (int i = 0; i < sentence.length(); i++) {
        char ch = sentence[i];
        if (!inWord && !isBoundary(ch)) {
            inWord = true;
            wordLength++;
            startPositions.push_back(i);
        } else if (inWord) {
            if (isBoundary(ch)) {
                inWord = false;
                lengths.push_back(wordLength);
                wordLength = 0;
            } else {
                wordLength++;
            }
        }
    }
    if (inWord) {
        inWord = false;
        lengths.push_back(wordLength);
        wordLength = 0;
    }
}

/**
 * Allocates and returns a new array (of strings), that contains all the 
 * words in the given sentence.  
 * @param sentence input sentence
 * @param outWordsArrSize output array length
 * @return string array pointer
 */
string* createWordsArray(const string& sentence, int& outWordsArrSize) {
    vector<int> startPositions;
    vector<int> lengths;
    findBoundaries(sentence, startPositions, lengths);
    assert(startPositions.size() == lengths.size());
    outWordsArrSize = startPositions.size();
    string* words = new string[outWordsArrSize];
    for (int i = 0; i < outWordsArrSize; i++) {
        int startPosition = startPositions[i];
        int length = lengths[i];
        words[i] = sentence.substr(startPosition, length);   
    }
    return words;
}

void testCreateWordsArray(const char* inputSentence, const vector<string>& expected) {
    const string sentenceString(inputSentence);
    int numWords = 0;
    string* wordsArray = createWordsArray(sentenceString, numWords);
    if (expected.size() != numWords) {
        cerr << "input: \"" << inputSentence << "\"" << endl;
        cerr << "expected.size() == " << expected.size() << " != " << numWords << " == numWords" << endl;        
    }
    assert(expected.size() == numWords);
    for (int i = 0; i < numWords; i++) {
        if (expected[i] != wordsArray[i]) {
            cerr << "input: \"" << inputSentence << "\"" << endl;
            cerr << "arrays differ at index " << i << "; " << expected[i] << " != " << wordsArray[i] << endl;
        }
        assert(expected[i] == wordsArray[i]);
    }
}

int main() {
    vector<string> expectedCommon = {"You", "can", "do", "it"};
    testCreateWordsArray("You can do it", expectedCommon);
    testCreateWordsArray(" You can do it", expectedCommon);
    testCreateWordsArray("You can do it ", expectedCommon);
    testCreateWordsArray("You     can do  it", expectedCommon);
    testCreateWordsArray(" You can do it", expectedCommon);
    vector<string> oneWord = {"One"};
    testCreateWordsArray("One", oneWord);
    vector<string> empty = {};
    testCreateWordsArray("", empty);
    vector<string> expected8 = {};
    testCreateWordsArray(" ", empty);
    vector<string> twoWords = {"Two", "words"};
    testCreateWordsArray("Two words", twoWords);
    vector<string> punctuated = {"You", "can", "do", "it"};
    testCreateWordsArray("You, can do it!", punctuated);
    return 0;
}
