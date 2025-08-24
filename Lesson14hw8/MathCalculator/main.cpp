#include <iostream>
#include "mathlib.h"

using namespace std;


void showMenu() {
    cout << "\n=== Mathematical Calculator ===" << endl;
    cout << "1. Basic operations         (add, subtract, multiply, divide)" << endl;
    cout << "2. Mathematical functions   (power, squareRoot, absoluteValue)" << endl;
    cout << "3. Working with arrays      (findMax, findMin, calculateSum, calculateAverage, sortArray)" << endl;
    cout << "4. Working with integers    (factorial, isPrime, gcd)" << endl;
    cout << "5. Utility functions        (isEven, isOdd, fibonacci)" << endl;
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
            cout << "Select function: (1)add; (2)subtract; (3)multiply; (4)divide;" << endl;
            cout << "Choose option: ";

            int searchType;
            cin >> searchType;

            if (searchType == 1) {

                cout << "Type = 1" << endl;
                // auto results = library.findByTitle(search);
                // cout << "\n🔍 Found " << results.size() << " books:" << endl;
                // for (const auto& book : results) {
                //     cout << book.getInfo() << endl;
                // }
            }
            else if (searchType == 2) {

                cout << "Type = 2" << endl;
                // auto results = library.findByAuthor(search);
                // cout << "\n🔍 Found " << results.size() << " books:" << endl;
                // for (const auto& book : results) {
                //     cout << book.getInfo() << endl;
                // }
            }
            else if (searchType == 3) {
                cout << "Type = 3" << endl;
            }
            else {
                cout << "Type = 4" << endl;
            }


            // cout << "✅ Book added!" << endl;
            break;
        }
        case 2:
            cout << "Case = 2" << endl;
            // library.showAllBooks();
            break;

        case 3: {
            cout << "Case = 3" << endl;
            // string search;
            // cout << "Search by (1)Title or (2)Author: ";
            // int searchType;
            // cin >> searchType;
            // cout << "Enter search term: ";
            // cin.ignore();
            // getline(cin, search);

            // if (searchType == 1) {
            //     auto results = library.findByTitle(search);
            //     cout << "\n🔍 Found " << results.size() << " books:" << endl;
            //     for (const auto& book : results) {
            //         cout << book.getInfo() << endl;
            //     }
            // }
            // else {
            //     auto results = library.findByAuthor(search);
            //     cout << "\n🔍 Found " << results.size() << " books:" << endl;
            //     for (const auto& book : results) {
            //         cout << book.getInfo() << endl;
            //     }
            // }
            break;
        }
        case 4: {
            cout << "Case = 4" << endl;
            // int bookId;
            // cout << "Enter book ID to borrow: ";
            // cin >> bookId;
            // if (library.borrowBook(bookId)) {
            //     cout << "✅ Book borrowed successfully!" << endl;
            // }
            // else {
            //     cout << "❌ Cannot borrow book (not available or not found)" << endl;
            // }
            break;
        }
        case 5: {
            cout << "Case = 5" << endl;
            // int bookId;
            // cout << "Enter book ID to return: ";
            // cin >> bookId;
            // if (library.returnBook(bookId)) {
            //     cout << "✅ Book returned successfully!" << endl;
            // }
            // else {
            //     cout << "❌ Cannot return book (not borrowed or not found)" << endl;
            // }
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
