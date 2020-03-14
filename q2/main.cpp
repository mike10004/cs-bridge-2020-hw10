// mac937@nyu.edu
// hw10 question 2

#include <iostream>
#include <cassert>
#include <vector>   // for testing 
#include <algorithm>  // for testing
using namespace std;

int* findMissing(const int arr[], int n, int& resArrSize) {
    return nullptr;
}

void testFindMissing(const vector<int>& input, const vector<int>& expected) {
    int actualSize = 0;
    int* actual = findMissing(input.data(), input.size(), actualSize);
    delete[] actual;
}

void testFindMissingAllPermutations(const vector<int>& input, const vector<int>& expected) {
    int* copy = new int[input.size()];
    int length = input.size();
    for (int i = 0; i < input.size(); i++) {
        copy[i] = input[i];
    }
    do {
        vector<int> permutation;
        permutation.assign(copy, copy + length);
        testFindMissing(permutation, expected);
    } while ( next_permutation(copy, copy + length) );
    delete[] copy;
}

int main() {
    testFindMissingAllPermutations({3, 1, 3, 0, 6, 4}, {2, 5});
    testFindMissingAllPermutations({}, {});
    testFindMissingAllPermutations({1}, {0});
    testFindMissingAllPermutations({0}, {1});
    testFindMissingAllPermutations({0, 0, 0}, {1, 2});
    testFindMissingAllPermutations({1, 2, 3, 4}, {0});
    testFindMissingAllPermutations({0, 2, 3, 4}, {0});
    testFindMissingAllPermutations({0, 1, 3, 4}, {0});
    testFindMissingAllPermutations({0, 1, 2, 4}, {0});
    testFindMissingAllPermutations({0, 1, 2, 3}, {4});
    testFindMissingAllPermutations({0, 0, 3, 3}, {4});
    testFindMissingAllPermutations({0, 1, 1, 3}, {4});
    testFindMissingAllPermutations({}, {});
    return 0;
}
