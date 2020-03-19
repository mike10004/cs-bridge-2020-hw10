// mac937@nyu.edu
// hw10 question 2

#include <iostream>
#include <cassert>
#include <vector>   // for testing 

using namespace std;

/**
 * Counts the number of elements in an array that are equal to a query value.
 * @param array an array
 * @param arrayLength 
 * @return number of elements equal to the query value 
 */
int countEqualElements(const int *array, int arrayLength, int query) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (array[i] == query) {
            count++;
        }
    }
    return count;
}

/**
 * Finds the missing numbers in an array. Given an array of 
 * length n, this function returns a newly allocated array 
 * containing all the numbers in the range [0..n] that are 
 * not present in the array.
 * @param arr the array
 * @param n length of the array
 * @param resArrSize size of the newly allocated array
 * @return a newly allocated array that must be deleted explicitly
 */
int* findMissing(const int arr[], int n, int& resArrSize) {
    int* allNumbers = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        allNumbers[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        assert(arr[i] >= 0 && arr[i] <= n);
        allNumbers[arr[i]]++;
    }
    resArrSize = countEqualElements(allNumbers, n + 1, 0);
    assert(resArrSize > 0);
    int* missing = new int[resArrSize];
    int missingIndex = 0;
    for (int i = 0; i < n + 1; i++) {
        if (allNumbers[i] == 0) {
            missing[missingIndex] = i;
            missingIndex++;
        }
    }
    delete[] allNumbers;
    return missing;
}

/**
 * Prints a vector of values and a newline.
 * @param values values
 */
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

/**
 * Tests the findMissing function.
 * @param input vector passed as an array to findMissing
 * @param expected expected result
 */
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

/**
 * Tests the find missing function for an input of length 4, iterating
 * through all permutations of the input sequence.
 * @param input unpermuted input sequence
 * @param expected expected result
 */
void testFindMissingAllPermutationsOf4Elements(const vector<int>& input, const vector<int>& expected) {
    int n = input.size();
    assert(n == 4);
    int permutations[24][4] = {
            {0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1},
            {0, 3, 1, 2}, {0, 3, 2, 1}, {1, 0, 2, 3}, {1, 0, 3, 2},
            {1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0},
            {2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3}, {2, 1, 3, 0},
            {2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1},
            {3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0}      
    };
    for (int i = 0; i < 24; i++) {
        vector<int> permutation;
        permutation.reserve(n);
        for (int j = 0; j < 4; j++) {
            permutation.push_back(input[permutations[i][j]]);
        }
        testFindMissing(permutation, expected);
    }
}

/**
 * Runs though several test cases.
 * @return zero on clean exit, nonzero on assertion failure
 */
int main() {
    testFindMissing({3, 1, 3, 0, 6, 4}, {2, 5});
    testFindMissing({}, {0});
    testFindMissing({1}, {0});
    testFindMissing({0}, {1});
    testFindMissing({0, 0, 0}, {1, 2, 3});
    testFindMissingAllPermutationsOf4Elements({1, 2, 3, 4}, {0});
    testFindMissingAllPermutationsOf4Elements({0, 2, 3, 4}, {1});
    testFindMissingAllPermutationsOf4Elements({0, 1, 3, 4}, {2});
    testFindMissingAllPermutationsOf4Elements({0, 1, 2, 4}, {3});
    testFindMissingAllPermutationsOf4Elements({0, 1, 2, 3}, {4});
    testFindMissingAllPermutationsOf4Elements({0, 1, 1, 3}, {2, 4});
    testFindMissingAllPermutationsOf4Elements({0, 0, 3, 3}, {1, 2, 4});
    return 0;
}
