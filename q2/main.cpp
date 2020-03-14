// mac937@nyu.edu
// hw10 question 2

#include <iostream>
#include <cassert>
#include <vector>   // for testing 
#include <algorithm>  // for testing
using namespace std;

int countMissing(const int counts[], int numCounts) {
    int numMissing = 0;
    for (int i = 0; i < numCounts; i++) {
        if (counts[i] == 0) {
            numMissing++;
        }
    }
    return numMissing;
}

int* findMissing(const int arr[], int n, int& resArrSize) {
    int* allNumbers = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        allNumbers[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        assert(arr[i] >= 0 && arr[i] <= n);
        allNumbers[arr[i]]++;
    }
    resArrSize = countMissing(allNumbers, n + 1);
    assert(resArrSize > 0);
    int* missing = new int[resArrSize];
    int missingIndex = 0;
    for (int i = 0; i < n + 1; i++) {
        if (allNumbers[i] == 0) {
            missing[missingIndex] = i;
            missingIndex++;
        }
    }
    return missing;
}

void printVector(const vector<int>& values) {
    cout << "[";
    for (int i = 0; i < values.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << values[i];
    }
    cout << "]";
    cout << endl;
}

void testFindMissing(const vector<int>& input, const vector<int>& expected) {
    int actualSize = 0;
    int* actual = findMissing(input.data(), input.size(), actualSize);
    if (actualSize != expected.size()) {
        printVector(input);
        printVector(expected);
        cout << "size of actual " << actualSize << " != " << expected.size() << " (expected size)" << endl;
    }
    assert(actualSize == expected.size());
    for (int i = 0; i < actualSize; i++) {
        if (expected[i] != actual[i]) {
            printVector(input);
            printVector(expected);
            cout << "expected[" << i << "] = " << expected[i] << " != " << actual[i] << " = actual[" << i << "]" << endl;
        }
        assert(expected[i] == actual[i]);
    }
    delete[] actual;
}

void testFindMissingAllPermutations(const vector<int>& input, const vector<int>& expected) {
    int* copy = new int[input.size()];
    int length = input.size();
    for (int i = 0; i < input.size(); i++) {
        copy[i] = input[i];
    }
    do {
        vector<int> permutation(length);
        permutation.assign(copy, copy + length);
        testFindMissing(permutation, expected);
    } while ( next_permutation(copy, copy + length) );
    delete[] copy;
}

int main() {
    testFindMissingAllPermutations({3, 1, 3, 0, 6, 4}, {2, 5});
    testFindMissingAllPermutations({}, {0});
    testFindMissingAllPermutations({1}, {0});
    testFindMissingAllPermutations({0}, {1});
    testFindMissingAllPermutations({0, 0, 0}, {1, 2, 3});
    testFindMissingAllPermutations({1, 2, 3, 4}, {0});
    testFindMissingAllPermutations({0, 2, 3, 4}, {1});
    testFindMissingAllPermutations({0, 1, 3, 4}, {2});
    testFindMissingAllPermutations({0, 1, 2, 4}, {3});
    testFindMissingAllPermutations({0, 1, 2, 3}, {4});
    testFindMissingAllPermutations({0, 1, 1, 3}, {2, 4});
    testFindMissingAllPermutations({0, 0, 3, 3}, {1, 2, 4});
    return 0;
}
