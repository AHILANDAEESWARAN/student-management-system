#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    bool isIssued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        isIssued = false;
    }

    void displayBook() {
        cout << "\nBook ID   : " << bookID;
        cout << "\nTitle     : " << title;
        cout << "\nAuthor    : " << author;
        cout << "\nStatus    : ";

        if (isIssued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n---------------------------";
    }
};

class Member {
public:
    int memberID;
    string memberName;

    Member(int id, string name) {
        memberID = id;
        memberName = name;
    }
};

vector<Book> books;
vector<Member> members;

void addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {

    if (books.empty()) {
        cout << "\nNo Books Available!\n";
        return;
    }

    for (int i = 0; i < books.size(); i++) {
        books[i].displayBook();
    }
}

void addMember() {
    int id;
    string name;

    cout << "\nEnter Member ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "\nMember Added Successfully!\n";
}

void issueBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++) {

        if (books[i].bookID == id) {

            if (!books[i].isIssued) {
                books[i].isIssued = true;
                cout << "\nBook Issued Successfully!\n";
            }

            else {
                cout << "\nBook Already Issued!\n";
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBook Not Found!\n";
    }
}

void returnBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++) {

        if (books[i].bookID == id) {

            if (books[i].isIssued) {
                books[i].isIssued = false;
                cout << "\nBook Returned Successfully!\n";
            }

            else {
                cout << "\nBook Was Not Issued!\n";
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBook Not Found!\n";
    }
}

void searchBook() {
    string keyword;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Book Title or Author: ";
    getline(cin, keyword);

    for (int i = 0; i < books.size(); i++) {

        if (books[i].title == keyword || books[i].author == keyword) {
            books[i].displayBook();
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo Matching Book Found!\n";
    }
}

int main() {

    int choice;

    do {

        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Add Member\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                addMember();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                searchBook();
                break;

            case 7:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
