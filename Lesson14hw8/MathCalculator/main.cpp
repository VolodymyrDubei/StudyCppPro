#include <iostream>
#include <limits>
#include "mathlib.h"

using namespace std;


void showMenu();

int correctInputForMenu();

double correctInputDouble();

int correctInputInt();

void inputArray(double[], int);

double arrayFunctionOutput(double (*func)(const double*, int));

void Demonstration();


int main() {

    cout << "\nWelcome to Mathematical Calculator!" << endl;
    cout << "Using Static Library (.a)" << endl;

    int choice;
    do {
        showMenu();
        //cin >> choice;
        choice = correctInputForMenu();

        switch(choice) {
            case 1: {
                int searchType;
                do {
                    cout << "\nBasic operations - Select function:" << endl;
                    cout << "1. add(a, b)" << endl;
                    cout << "2. subtract(a, b)" << endl;
                    cout << "3. multiply(a, b)" << endl;
                    cout << "4. divide(a, b)" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Choose function: ";

                    //cin >> searchType;
                    searchType = correctInputForMenu();

                    switch(searchType) {
                        case 1: {
                            double valueA = correctInputDouble();
                            double valueB = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << add(valueA, valueB) << endl;
                            break;
                        }
                        case 2: {
                            double valueA = correctInputDouble();
                            double valueB = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << subtract(valueA, valueB) << endl;
                            break;
                        }
                        case 3: {
                            double valueA = correctInputDouble();
                            double valueB = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << multiply(valueA, valueB) << endl;
                            break;
                        }
                        case 4: {
                            double valueA = correctInputDouble();
                            double valueB = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << divide(valueA, valueB) << endl;
                            break;
                        }
                        case 0: {
                            cout << "Return to the main menu!" << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                        }
                    }
                } while (searchType != 0);
                break;
            }
            case 2: {
                int searchType;
                do {
                    cout << "\nMathematical functions - Select function:" << endl;
                    cout << "1. power(a, b)" << endl;
                    cout << "2. squareRoot(a)" << endl;
                    cout << "3. absoluteValue(a)" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Choose function: ";

                    //cin >> searchType;
                    searchType = correctInputForMenu();

                    switch(searchType) {
                        case 1: {
                            double valueA = correctInputDouble();
                            int valueB = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << power(valueA, valueB) << endl;
                            break;
                        }
                        case 2: {
                            double valueA = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << squareRoot(valueA) << endl;
                            break;
                        }
                        case 3: {
                            double valueA = correctInputDouble();
                            cout << "\nResult function " << "(" << searchType << ") = " << absoluteValue(valueA) << endl;
                            break;
                        }
                        case 0: {
                            cout << "Return to the main menu!" << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                        }
                    }

                } while (searchType != 0);
                break;
            }
            case 3: {
                int searchType;
                do {
                    cout << "\nWorking with integers - Select function:" << endl;
                    cout << "1. factorial(a)" << endl;
                    cout << "2. isPrime(a)" << endl;
                    cout << "3. gcd(a, b)" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Choose function: ";

                    //cin >> searchType;
                    searchType = correctInputForMenu();

                    switch(searchType) {
                        case 1: {
                            int valueA = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << factorial(valueA) << endl;
                            break;
                        }
                        case 2: {
                            int valueA = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << ((isPrime(valueA)) ? "True!" : "False!") << endl;
                            break;
                        }
                        case 3: {
                            int valueA = correctInputInt();
                            int valueB = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << gcd(valueA, valueB) << endl;
                            break;
                        }
                        case 0: {
                            cout << "Return to the main menu!" << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                        }
                    }

                } while (searchType != 0);
                break;
            }
            case 4: {
                int searchType;
                do {
                    cout << "\nUtility functions - Select function:" << endl;
                    cout << "1. isEven(a)" << endl;
                    cout << "2. isOdd(a)" << endl;
                    cout << "3. fibonacci(a)" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Choose function: ";

                    //cin >> searchType;
                    searchType = correctInputForMenu();

                    switch(searchType) {
                        case 1: {
                            int valueA = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << ((isEven(valueA)) ? "True!" : "False!") << endl;
                            break;
                        }
                        case 2: {
                            int valueA = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << ((isOdd(valueA)) ? "True!" : "False!") << endl;
                            break;
                        }
                        case 3: {
                            int valueA = correctInputInt();
                            cout << "\nResult function " << "(" << searchType << ") = " << fibonacci(valueA) << endl;
                            break;
                        }
                        case 0: {
                            cout << "Return to the main menu!" << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                        }
                    }

                } while (searchType != 0);
                break;
            }
            case 5: {
                int searchType;
                do {
                    cout << "\nWorking with arrays - Select function:" << endl;
                    cout << "1. findMax(arr[], size)" << endl;
                    cout << "2. findMin(arr[], size)" << endl;
                    cout << "3. calculateSum(arr[], size)" << endl;
                    cout << "4. calculateAverage(arr[], size)" << endl;
                    cout << "5. sortArray(arr[], size)" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Choose function: ";

                    //cin >> searchType;
                    searchType = correctInputForMenu();

                    switch(searchType) {
                        case 1: {
                            double result = arrayFunctionOutput(findMax);
                            cout << "\nResult function " << "(" << searchType << ") = " << result << endl;
                            break;
                        }
                        case 2: {
                            double result = arrayFunctionOutput(findMin);
                            cout << "\nResult function " << "(" << searchType << ") = " << result << endl;
                            break;
                        }
                        case 3: {
                            double result = arrayFunctionOutput(calculateSum);
                            cout << "\nResult function " << "(" << searchType << ") = " << result << endl;
                            break;
                        }
                        case 4: {
                            double result = arrayFunctionOutput(calculateAverage);
                            cout << "\nResult function " << "(" << searchType << ") = " << result << endl;
                            break;
                        }
                        case 5: {
                            cout << "\nEnter the array size. ";
                            int size = correctInputInt();
                            double* arr = new double[size];

                            inputArray(arr, size);
                            sortArray(arr, size);

                            cout << "\nSorted array: ";
                            for (int i = 0; i < size; i++) {
                                cout << arr[i] << " ";
                            }
                            cout << endl;

                            delete[] arr;
                            break;
                        }
                        case 0: {
                            cout << "Return to the main menu!" << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                        }
                    }

                } while (searchType != 0);
                break;
            }
            case 6: {
                Demonstration();
                break;
            }

            case 0:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 0);

    return 0;
}



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


double correctInputDouble() {
    cout << "Enter values: ";
    double number;

    while (true) {
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            cout << "Enter values: ";
        } else {
            break;
        }
    }
    return number;
}


int correctInputInt() {
    cout << "Enter values: ";
    int number;

    while (true) {
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            cout << "Enter values: ";
        } else {
            break;
        }
    }
    return number;
}


int correctInputForMenu() {
    int number;

    while (true) {
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            cout << "Choose option: ";
        } else {
            break;
        }
    }
    return number;
}


void inputArray(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        while (true) {
            cout << "Enter values Arr [" << i << "]: ";
            cin >> arr[i];

            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again.\n";
                cout << "Enter values Arr [" << i << "]: ";
            } else {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }
}


double arrayFunctionOutput(double (*func)(const double*, int)) {

    cout << "\nEnter the array size. ";
    int size = correctInputInt();
    double* arr = new double[size];

    inputArray(arr, size);

    double res = func(arr, size);

    delete[] arr;

    return res;
}


void Demonstration() {
    cout << "\n=== Demonstration of the functions ===" << endl;

    cout << "\n1. Basic operations:" << endl;
    cout << "1.1. add(4, 5) = " << add(4, 5) << endl;
    cout << "1.2. subtract(9, 4) = " << subtract(9, 4) << endl;
    cout << "1.3. multiply(3, 5) = " << multiply(3, 5) << endl;
    cout << "1.4. divide(9, 2) = " << divide(9, 2) << endl;

    cout << "\n2. Mathematical functions:" << endl;
    cout << "2.1. power(5, 2) = " << power(5, 2) << endl;
    cout << "2.2. squareRoot(45) = " << squareRoot(45) << endl;
    cout << "2.3. absoluteValue(-3) = " << absoluteValue(-3) << endl;

    cout << "\n3. Working with integers:" << endl;
    cout << "3.1. factorial(5) = " << factorial(5) << endl;
    cout << "3.2. isPrime(7) = " << isPrime(7) << endl;
    cout << "3.3. gcd(6, 4) = " << gcd(6, 4) << endl;

    cout << "\n4. Utility functions:" << endl;
    cout << "4.1. isEven(14) = " << ((isEven(14)) ? "True!" : "False!") << endl;
    cout << "4.2. isOdd(14) = " << ((isOdd(14)) ? "True!" : "False!") << endl;
    cout << "4.3. fibonacci(9) = " << fibonacci(9) << endl;

    cout << "\n5. Working with arrays:" << endl;
    cout << "5.1. findMax(arr[8, 5, 2, 52, 43], 5) = 52" << endl;
    cout << "5.2. findMin(arr[8, 5, 2, 52, 43], 5) = 2" << endl;
    cout << "5.3. calculateSum(arr[8, 5, 2, 52, 43], 5) = 110" << endl;
    cout << "5.4. calculateAverage(arr[8, 5, 2, 52, 43], 5) = 22" << endl;
    cout << "5.5. sortArray(arr[8, 5, 2, 52, 43], 5) = 2, 5, 8, 43, 52" << endl;
}
