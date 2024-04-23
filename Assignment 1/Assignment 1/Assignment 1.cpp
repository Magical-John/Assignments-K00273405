#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 14;

struct ListType {
    string info[MAX_SIZE];
    int length;
};

void InsertionSort(ListType& list) {
    for (int i = 1; i < list.length; i++) {
        string key = list.info[i];
        int j = i - 1;
        while (j >= 0 && list.info[j] > key) {
            list.info[j + 1] = list.info[j];
            j = j - 1;
        }
        list.info[j + 1] = key;
    }
}

void BinarySearch(ListType list, string item, int& position, bool& found) {
    int first = 0;
    int last = list.length - 1;
    found = false;

    while (first <= last) {
        int midPoint = (first + last) / 2;
        if (list.info[midPoint] == item) {
            found = true;
            position = midPoint;
            return;
        }
        else if (list.info[midPoint] < item) {
            first = midPoint + 1;
        }
        else {
            last = midPoint - 1;
        }
    }
    position = first; // If not found, position is where it should be inserted
}

int main() {
    ListType list;
    list.length = MAX_SIZE;

    // Accepting user input for the array of strings
    cout << "Enter " << MAX_SIZE << " strings, one per line:" << endl;
    for (int i = 0; i < list.length; i++) {
        cout << "String " << i + 1 << ": ";
        cin >> list.info[i];
    }

    // Sorting the array
    InsertionSort(list);

    // Printing the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < list.length; i++) {
        cout << list.info[i] << " ";
    }
    cout << endl;

    // Loop for searching strings
    char choice;
    do {
        string searchItem;
        cout << "\nEnter a string to search for: ";
        cin >> searchItem;
        int position;
        bool found;
        BinarySearch(list, searchItem, position, found);
        if (found) {
            cout << "Item found at position " << position << endl;
        }
        else {
            cout << "Item not found. Should be inserted at position " << position + 1 << endl;
        }

        cout << "\nDo you want to search again? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');

    cout << "Exiting program." << endl;

    return 0;
}