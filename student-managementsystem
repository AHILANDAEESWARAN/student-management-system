#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;
    string department;

    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Department: ";
        getline(cin, department);
    }

    void display() {
        cout << "\n----------------------------";
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nAge         : " << age;
        cout << "\nDepartment  : " << department;
        cout << "\n----------------------------\n";
    }
};

// Add Student
void addStudent() {
    Student s;

    ofstream file("students.txt", ios::app);

    s.input();

    file << s.rollNo << endl;
    file << s.name << endl;
    file << s.age << endl;
    file << s.department << endl;

    file.close();

    cout << "\nStudent Record Added Successfully!\n";
}

// Display Students
void displayStudents() {
    Student s;

    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo Records Found!\n";
        return;
    }

    while (file >> s.rollNo) {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.department);

        s.display();
    }

    file.close();
}

// Search Student
void searchStudent() {
    int roll;
    bool found = false;

    Student s;

    ifstream file("students.txt");

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    while (file >> s.rollNo) {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.department);

        if (s.rollNo == roll) {
            s.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nStudent Not Found!\n";
    }
}

// Delete Student
void deleteStudent() {
    int roll;
    bool found = false;

    Student s;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    while (file >> s.rollNo) {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.department);

        if (s.rollNo != roll) {
            temp << s.rollNo << endl;
            temp << s.name << endl;
            temp << s.age << endl;
            temp << s.department << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent Record Deleted Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}

// Update Student
void updateStudent() {
    int roll;
    bool found = false;

    Student s;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    while (file >> s.rollNo) {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.department);

        if (s.rollNo == roll) {
            cout << "\nEnter New Details:\n";
            s.input();
            found = true;
        }

        temp << s.rollNo << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.department << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent Record Updated Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
