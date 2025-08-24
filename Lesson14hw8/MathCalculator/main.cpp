#include <iostream>
#include "mathlib.h"

using namespace std;


void showMenu() {
    cout << "\n=== Mathematical Calculator ===" << endl;
    cout << "1. Basic operations         (add, subtract, multiply, divide)" << endl;
    cout << "2. Mathematical functions   (power, squareRoot, absoluteValue)" << endl;
    cout << "3. Working with integers    (factorial, isPrime, gcd)" << endl;
    cout << "4. Utility functions        (isEven, isOdd, fibonacci)" << endl;
    cout << "5. Working with arrays      (findMax, findMin, calculateSum, calculateAverage, sortArray)" << endl;
    cout << "6. Demonstration of all functions" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose option: ";
}


int main() {

    cout << "\nWelcome to Mathematical Calculator!" << endl;
    cout << "Using Static Library (.a)" << endl;

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nSelect function:" << endl;
            cout << "1. add(a, b)" << endl;
            cout << "2. subtract(a, b)" << endl;
            cout << "3. multiply(a, b)" << endl;
            cout << "4. divide(a, b)" << endl;
            cout << "Choose function: ";

            int searchType;
            cin >> searchType;

            cout << "\nEnter two values (separated by a space): ";
            double valuesA, valuesB;
            cin >> valuesA >> valuesB;

            double result;

            if (searchType == 1) {
                result = add(valuesA, valuesB);
            }
            else if (searchType == 2) {
                result = subtract(valuesA, valuesB);
            }
            else if (searchType == 3) {
                result = multiply(valuesA, valuesB);
            }
            else {
                result = divide(valuesA, valuesB);
            }

            cout << "Result function " << "(" << searchType << ") = "<< result << endl;

            break;
        }
        case 2: {
            cout << "\nSelect function:" << endl;
            cout << "1. power(a, b)" << endl;
            cout << "2. squareRoot(a)" << endl;
            cout << "3. absoluteValue(a)" << endl;
            cout << "Choose function: ";

            int searchType;
            cin >> searchType;

            double result;

            if (searchType == 1) {
                cout << "\nEnter two values (separated by a space): ";
                double valuesA, valuesB;
                cin >> valuesA >> valuesB;
                result = power(valuesA, valuesB);
            }
            else if (searchType == 2) {
                cout << "\nEnter one value: ";
                double valuesA;
                cin >> valuesA;
                result = squareRoot(valuesA);
            }
            else {
                cout << "\nEnter one value: ";
                double valuesA;
                cin >> valuesA;
                result = absoluteValue(valuesA);
            }

            cout << "Result function " << "(" << searchType << ") = "<< result << endl;

            break;
        }
        case 3: {
            cout << "\nSelect function:" << endl;
            cout << "1. factorial(a)" << endl;
            cout << "2. isPrime(a)" << endl;
            cout << "3. gcd(a, b)" << endl;
            cout << "Choose function: ";

            int searchType;
            cin >> searchType;

            if (searchType == 1) {
                cout << "\nEnter one value: ";
                int valuesA;
                cin >> valuesA;
                cout << "Result function " << "(" << searchType << ") = "<< factorial(valuesA) << endl;
            }
            else if (searchType == 2) {
                cout << "\nEnter one value: ";
                int valuesA;
                cin >> valuesA;
                cout << "Result function " << "(" << searchType << ") = " << ((isPrime(valuesA)) ? "True!" : "False!") << endl;
            }
            else {
                cout << "\nEnter two values (separated by a space): ";
                int valuesA, valuesB;
                cin >> valuesA >> valuesB;
                cout << "Result function " << "(" << searchType << ") = "<< gcd(valuesA, valuesB) << endl;
            }

            break;
        }
        case 4: {
            cout << "\nSelect function:" << endl;
            cout << "1. isEven(a)" << endl;
            cout << "2. isOdd(a)" << endl;
            cout << "3. fibonacci(a)" << endl;
            cout << "Choose function: ";

            int searchType;
            cin >> searchType;

            if (searchType == 1) {
                cout << "\nEnter one value: ";
                int valuesA;
                cin >> valuesA;
                cout << "Result function " << "(" << searchType << ") = " << ((isEven(valuesA)) ? "True!" : "False!") << endl;
            }
            else if (searchType == 2) {
                cout << "\nEnter one value: ";
                int valuesA;
                cin >> valuesA;
                cout << "Result function " << "(" << searchType << ") = " << ((isOdd(valuesA)) ? "True!" : "False!") << endl;
            }
            else {
                cout << "\nEnter one value: ";
                int valuesA;
                cin >> valuesA;
                cout << "Result function " << "(" << searchType << ") = " << fibonacci(valuesA) << endl;
            }

            break;
        }
        case 5: {
            cout << "\nSelect function:" << endl;
            cout << "1. findMax(arr[], size)" << endl;
            cout << "2. findMin(arr[], size)" << endl;
            cout << "3. calculateSum(arr[], size)" << endl;
            cout << "4. calculateAverage(arr[], size)" << endl;
            cout << "5. sortArray(arr[], size)" << endl;
            cout << "Choose function: ";

            int searchType;
            cin >> searchType;

            // double findMax(const double arr[], int size);  // максимум масиву
            // double findMin(const double arr[], int size);  //мінімум масиву
            // double calculateSum(const double arr[], int size); // сума елементів
            // double calculateAverage(const double arr[], int size);  // середнє арифметичне
            // void sortArray(double arr[], int size); // сортування масиву


            cout << "\nEnter the array size: ";
            int size;
            cin >> size;

            double* arr= new double[size];

            cout << "Enter " << size << " numbers (separated by a space): ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }


            double result;

            if (searchType == 1) {
                result = findMax(arr, size);
            }
            else if (searchType == 2) {
                result = findMin(arr, size);
            }
            else if (searchType == 3) {
                result = calculateSum(arr, size);
            }
            else if (searchType == 4) {
                result = calculateAverage(arr, size);
            }
            else {
                sortArray(arr, size);

                cout << "Sorted array: ";
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                delete[] arr;

                break;
            }

            cout << "Result function " << "(" << searchType << ") = "<< result << endl;

            delete[] arr;

            break;
        }
        case 6: {
            cout << "Case = 6" << endl;
            // cout << "\n📊 Library Statistics:" << endl;
            // cout << library.getLibraryInfo() << endl;
            // cout << "Borrowed: " << library.getBorrowedBooks() << endl;
            break;
        }

        case 0:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid option!" << endl;
        }
    } while (choice != 0);

    //return a.exec();
    return 0;
}
