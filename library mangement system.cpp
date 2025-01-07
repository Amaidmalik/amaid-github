

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
<<<<<<< HEAD
//hjhjhkshkhskhjash
//=======cv
//hjhjhkshkhskd
>>>>>>> 40f3710456a42b2ae6f2a86745e80bd6ad8bfafe
// Structure to store book details
//amaid sdsdsd
struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};

// Function prototypes
void addBook(vector<Book>& books);
void searchBook(const vector<Book>& books);
void displayBooks(const vector<Book>& books);
void saveToFile(const vector<Book>& books);
void loadFromFile(vector<Book>& books);

int main() {
    vector<Book> books;
    loadFromFile(books);

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(books);
            break;
        case 2:
            searchBook(books);
            break;
        case 3:
            displayBooks(books);
            break;
        case 4:
            saveToFile(books);
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new book
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.bookID;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Author Name: ";
    getline(cin, newBook.author);
    cout << "Enter Quantity: ";
    cin >> newBook.quantity;

    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook(const vector<Book>& books) {
    int searchID;
    string searchTitle;
    cout << "Search by:\n1. Book ID\n2. Book Title\nEnter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter Book ID: ";
        cin >> searchID;
        for (const auto& book : books) {
            if (book.bookID == searchID) {
                cout << "Book Found:\n";
                cout << "ID: " << book.bookID << ", Title: " << book.title
                     << ", Author: " << book.author << ", Quantity: " << book.quantity << "\n";
                return;
            }
        }
    } else if (choice == 2) {
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, searchTitle);
        for (const auto& book : books) {
            if (book.title == searchTitle) {
                cout << "Book Found:\n";
                cout << "ID: " << book.bookID << ", Title: " << book.title
                     << ", Author: " << book.author << ", Quantity: " << book.quantity << "\n";
                return;
            }
        }
    }

    cout << "Book not found.\n";
}

// Function to display all books
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available in the inventory.\n";
        return;
    }

    cout << "\nAvailable Books:\n";
    for (const auto& book : books) {
        cout << "ID: " << book.bookID << ", Title: " << book.title
             << ", Author: " << book.author << ", Quantity: " << book.quantity << "\n";
    }
}

// Function to save books to a file
void saveToFile(const vector<Book>& books) {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.bookID << "," << book.title << "," << book.author << "," << book.quantity << "\n";
        }
        file.close();
        cout << "Books saved to file successfully.\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

// Function to load books from a file
void loadFromFile(vector<Book>& books) {
    ifstream file("books.txt");
    if (file.is_open()) {
        Book book;
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            pos = line.find(",");
            book.bookID = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.title = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.author = line.substr(0, pos);
            line.erase(0, pos + 1);

            book.quantity = stoi(line);

            books.push_back(book);
        }
        file.close();
        cout << "Books loaded from file successfully.\n";
    } else {
        cout << "No existing file found. Starting fresh.\n";
    }
}

