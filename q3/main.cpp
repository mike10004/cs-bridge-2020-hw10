// mac937@nyu.edu
// hw10 question 3

#include <iostream>
#include <vector>

using namespace std;

int countAppearances(const int* haystack, int haystackLength, int needle) {
    int count = 0;
    for (int i = 0; i < haystackLength; i++) {
        if (needle == haystack[i]) {
            count++;
        }
    }
    return count;
}

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
 * Implementation that uses a vector to store input numbers.
 * @return zero on success 
 */
int main1() {
    return 0;
}

/**
 * Implementation that uses a vector to store input numbers.
 * @return 
 */
int main2() {
    vector<int> numbers;
    int query;
    cout << "Please enter a sequence of positive integers, each in a separate line.\n"
            "End your input by typing -1." << endl;
    int userInput;
    do {
        cin >> userInput;
        if (userInput > 0) {
            numbers.push_back(userInput);        
        }
    } while (userInput > 0);
    cout << "Please enter the number you want to search for." << endl;
    cin >> query;
    searchAndPrint(numbers.data(), numbers.size(), query);
    return 0;
}

int main() {
    return main1() + main2();
}