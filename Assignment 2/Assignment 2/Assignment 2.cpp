#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   

using namespace std;


int partition(string arr[], int low, int high) {
    string pivot = arr[high]; // pivot=last element
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].compare(pivot) < 0) { 
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // sort elements using recursion
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int binarySearch(string arr[], int low, int high, string key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == key)
            return mid;

        
        if (arr[mid] < key)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
   
    return -1;
}

int main() {
    int menu;
    bool quit = false;

    do {
        cout << "***********MENU***********" << endl;
        cout << " 1 - Sort and Search in an Array of Strings" << endl;
        cout << " 2 - Guess The Number " << endl;
        cout << " 3 - Exit." << endl;
        cout << " Enter your choice and press enter:" << endl;
        cout << "***********MENU***********" << endl;

        cin >> menu;

        switch (menu) {
        case 1: {
            const int SIZE = 14;
            string strings[SIZE];

            cout << "Enter " << SIZE << " strings:" << endl;

            
            for (int i = 0; i < SIZE; ++i) {
                cout << "String " << i + 1 << ": ";
                cin >> strings[i];
            }

            //sort the array
            quickSort(strings, 0, SIZE - 1);

            
            cout << "\nSorted strings:" << endl;
            for (int i = 0; i < SIZE; ++i) {
                cout << "String " << i + 1 << ": " << strings[i] << endl;
            }

            // Search the array
            string key;
            cout << "\nEnter a string to search: ";
            cin >> key;
            int index = binarySearch(strings, 0, SIZE - 1, key);
            if (index != -1) {
                cout << "String found at index: " << index << endl;
            }
            else {
                cout << "String not found." << endl;
            }
            break;
        }
        case 2: {
            srand(time(0)); // Seed the random number generator with the current time

            
            int randomNumber = rand() % 1000 + 1;

            int guess;
            int attempts = 0;
            const int maxAttempts = 10;

            cout << "Welcome to the Guess the Number game!" << endl;
            cout << "I have selected a number between 1 and 1000. You have " << maxAttempts << " attempts to guess it." << endl;

            
            while (attempts < maxAttempts) {
                cout << "Attempt " << attempts + 1 << ": Enter your guess: ";
                cin >> guess;

                if (guess == randomNumber) {
                    cout << "Congratulations! You guessed the number " << randomNumber << " correctly!" << endl;
                    break;
                }
                else if (guess < randomNumber) {
                    cout << "Too low. Try again." << endl;
                }
                else {
                    cout << "Too high. Try again." << endl;
                }

                attempts++;
            }

            
            if (attempts == maxAttempts) {
                cout << "Sorry, you have used all your attempts. The number was " << randomNumber << "." << endl;
            }
            break;
        }
        case 3:
            cout << "EXIT" << endl;
            quit = true;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
    } while (!quit);

    return 0;
}
