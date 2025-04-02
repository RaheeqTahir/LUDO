#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isRegistered(const string& username) {
    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        if (line.find(username) != string::npos) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    
    if (isRegistered(username)) {
        cout << "Username already exists. Try a different one." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid credentials!" << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
