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
 * @return true if and only if the character is not a digit, US English alphabet letter, hyphen, or apostrophe 
 */
bool isBoundary(char ch) {
    return !((ch >= 'A' && ch <= 'Z')
            || (ch >= 'a' && ch <= 'z')
            || (ch >= '0' && ch <= '9')
            || (ch == '\'')
            || (ch == '-'));
}

/**
 * Finds the boundaries of words in a sentence. Scans
 * each character in the string, checking whether it is a 
 * boundary character, and recording the positions 
 * appropriately. Time complexity is O(n) where n is string length.
 * @param sentence sentence
 * @param startPositions vector to accumulate word start positions
 * @param lengths vector to accumulate word lengths
 */
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
        lengths.push_back(wordLength);
    }
}

/**
 * Allocates and returns a new array (of strings), that contains all the 
 * words in the given sentence. Calls findBoundaries to gather the word 
 * boundaries into vectors, allocates an array for the words, and then 
 * copies each substring defined by the word boundaries into an array.
 * The substrings are disjoint, so at most each character in the input
 * string is copied. Time complexity is O(n).
 * 
 * The hyphen and apostrophe characters are treated as letters, even if 
 * they are on their own (and not parts of words), so you may get weird 
 * results on degenerate input like "Foo ---- bar". 
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
        words[i].assign(sentence.substr(startPosition, length));   
    }
    return words;
}

/**
 * Tests the createWordsArray function.
 */
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
    delete[] wordsArray;
}

/**
 * Runs through a number of test cases of the createWordsArray function.
 * @return zero on clean operation; nonzero on assertion failure
 */
int main() {
    vector<string> expectedYouCanDoIt = {"You", "can", "do", "it"};
    testCreateWordsArray("You can do it", expectedYouCanDoIt);
    testCreateWordsArray(" You can do it", expectedYouCanDoIt);
    testCreateWordsArray("You can do it ", expectedYouCanDoIt);
    testCreateWordsArray("You     can do  it", expectedYouCanDoIt);
    testCreateWordsArray(" You can do it ", expectedYouCanDoIt);
    testCreateWordsArray("You, can do it!", expectedYouCanDoIt);
    testCreateWordsArray("", {});
    testCreateWordsArray(" ", {});
    testCreateWordsArray("a", {"a"});
    testCreateWordsArray("One", {"One"});
    testCreateWordsArray("The movie 101 Dalmations is good.", 
            {"The", "movie", "101", "Dalmations", "is", "good"});
    testCreateWordsArray("A good-luck charm", {"A", "good-luck", "charm"});
    testCreateWordsArray("Mary's little lamb", {"Mary's", "little", "lamb"});
    testCreateWordsArray("Two words", {"Two", "words"});
    testCreateWordsArray("Go go Gadget chainsaw! Go go Gadget...", 
            {"Go", "go", "Gadget", "chainsaw", "Go", "go", "Gadget"});
    return 0;
}
