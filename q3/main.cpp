// mac937@nyu.edu
// hw10 question 3

#include <iostream>
#include <vector>

using namespace std;

typedef int* intarray;
const int CAPACITY_INCREASE_FACTOR = 2;

/**
 * Counts the appearances of a value in an array.
 * @param haystack the array
 * @param haystackLength the array length
 * @param needle the value to search for
 * @return the number of appearances
 */
int countAppearances(const int* haystack, int haystackLength, int needle) {
    int count = 0;
    for (int i = 0; i < haystackLength; i++) {
        if (needle == haystack[i]) {
            count++;
        }
    }
    return count;
}

/**
 * Prints the line numbers on which a certain value appears.
 * The line numbers are equal to one more than the array position.
 * @param haystack the array 
 * @param haystackLength the array length
 * @param needle value whose line numbers are to be printed
 */
void printLineNumbers(const int* haystack, int haystackLength, int needle) {
    int numShowings = 0;
    for (int i = 0; i < haystackLength; i++) {
        if (needle == haystack[i]) {
            if (numShowings > 0) {
                cout << ", ";
            }
            cout << (i + 1);
            numShowings++;
        }
    }
}

/**
 * Searches for instances of a value in an array and prints the line
 * numbers corresponding to those values.
 * @param haystack array
 * @param haystackLength array length 
 * @param needle value to search for
 */
void searchAndPrint(const int* haystack, int haystackLength, int needle) {
    int numAppearances = countAppearances(haystack, haystackLength, needle);
    cout << needle;
    if (numAppearances > 0) {
        if (numAppearances == 1) {
            cout << " shows in line ";
        } else {
            cout << " shows in lines ";
        }
        printLineNumbers(haystack, haystackLength, needle);
    } else {
        cout << " does not show in any lines";
    }
    cout << endl;
}

/**
 * Searches for instances of a value in a vector and prints the line
 * numbers corresponding to those values.
 * @param haystack vector of values
 * @param needle value to search for
 */
void searchAndPrint(const vector<int>& haystack, int needle) {
    searchAndPrint(haystack.data(), haystack.size(), needle);
}

/**
 * Copies values from one array to another.
 * @param src source array
 * @param srcStart start position in source array
 * @param dst destination array
 * @param dstStart start position in destination array
 * @param length number of values to copy
 */
void copyArray(int* src, int srcStart, int* dst, int dstStart, int length) {
    for (int i = 0; i < length; i++) {
        dst[dstStart + i] = src[srcStart + i];
    }
}

/**
 * Adds a value to an array, resizing the array if necessary.
 * Be careful that no copies of the array pointer you provide are 
 * used anywhere else, because the address may change.
 * @param numbers array of numbers
 * @param logicalLength logical length of the array
 * @param capacity allocated capacity of the array
 * @param appendage value to add
 */
void append(intarray& numbers, int& logicalLength, int& capacity, int appendage) {
    if (logicalLength + 1 > capacity) {
        capacity *= CAPACITY_INCREASE_FACTOR;
        int* temp = new int[capacity];
        copyArray(numbers, 0, temp, 0, logicalLength);
        delete[] numbers;
        numbers = temp;
    }
    numbers[logicalLength] = appendage;
    logicalLength++;
}

/**
 * Implementation that uses a dynamically-resized array to store input numbers.
 * @return zero on success 
 */
int main1() {
    int capacity = 1;
    int* numbers = new int[capacity];
    int logicalLength = 0;
    int query;
    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
            "End your input by typing -1." << endl;
    int userInput;
    cin >> userInput;
    while (userInput > 0) {
        append(numbers, logicalLength, capacity, userInput);
        cin >> userInput;
    }
    cout << "Please enter the number you want to search for." << endl;
    cin >> query;
    searchAndPrint(numbers, logicalLength, query);
    delete[] numbers;
    return 0;
}

/**
 * Implementation that uses a vector to store input numbers.
 * @return zero on clean exit 
 */
int main2() {
    vector<int> numbers;
    int query;
    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
            "End your input by typing -1." << endl;
    int userInput;
    cin >> userInput;
    while (userInput > 0) {
        numbers.push_back(userInput);
        cin >> userInput;
    } 
    cout << "Please enter the number you want to search for." << endl;
    cin >> query;
    searchAndPrint(numbers, query);
    return 0;
}

int main() {
    return main1() + main2();
}