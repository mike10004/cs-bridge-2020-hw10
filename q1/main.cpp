// mac937@nyu.edu
// hw10 question 1

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Allocates and returns a new array (of strings), that contains all the 
 * words in the given sentence.  
 * @param sentence input sentence
 * @param outWordsArrSize output array length
 * @return string array pointer
 */
string* createWordsArray(const string& sentence, int& outWordsArrSize) {
    
}

void testCreateWordsArray(const char* inputSentence, const vector<string>& expected) {
    const string sentenceString(inputSentence);
    int numWords = 0;
    string* wordsArray = createWordsArray(sentenceString, numWords);
    assert(expected.size() == numWords);
    for (int i = 0; i < numWords; i++) {
        assert(expected[i] == wordsArray[i]);
    }
}

int main() {
    vector<string> expected1 = {"You", "can", "do", "it"};
    testCreateWordsArray("You can do it", expected1);
    vector<string> expected2 = {"You", "can", "do", "it"};
    testCreateWordsArray(" You can do it", expected1);
    vector<string> expected3 = {"You", "can", "do", "it"};
    testCreateWordsArray("You can do it ", expected1);
    vector<string> expected4 = {"You", "can", "do", "it"};
    testCreateWordsArray("You     can do  it", expected1);
    vector<string> expected5 = {"You", "can", "do", "it"};
    testCreateWordsArray(" You can do it", expected1);
    vector<string> expected6 = {"One"};
    testCreateWordsArray("One", expected1);
    vector<string> expected7 = {};
    testCreateWordsArray("", expected1);
    vector<string> expected8 = {};
    testCreateWordsArray(" ", expected1);
    vector<string> expected9 = {"Two", "words"};
    testCreateWordsArray("Two words", expected1);    
    return 0;
}
