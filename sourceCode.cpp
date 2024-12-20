#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void passwordManager(int length) {
    string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@\#&-_+*%=/";
    string password;
    srand(time(0));
    for(int i = 0; i < length; i++) {
        password += character[rand() % character.size()];
    }
    cout << "Password: " << password << endl;

    cout << "Do you want to save password [Yes or No]: ";
    string confirmation;
    cin >> confirmation;
    if(confirmation == "Yes") {
        ofstream MyFile("savedPassword.txt", ios::app);
        string username;
        cout << "Username/Email: ";
        cin >> username;
        MyFile << username << ": " << password << "\n";
        MyFile.close();
        cout << "Password Saved" << endl;

        string check;
        cout << "Do you want to check saved passwords [Yes or No]: ";
        cin >> check;
        if(check == "Yes") {
            ifstream file;
            file.open("savedPassword.txt");
            if(file.is_open()) {
                string data;
                getline(file, data);

                while(!file.eof()) {
                    getline(file, data);
                    cout << data << "\n";
                }
                file.close();
            }
            else {
                cout << "Failed to open file" << endl;
            }
        }
        else if(check == "No") {
            cout << "Thank you" << endl;
        }
        else {
            cout << "Invalid operation, Please try again" << endl;
        }
    }
    else if(confirmation == "No") {
        cout << "Password Not Saved" << endl;
    }
    else {
        cout << "Invalid operation, Please try again" << endl;
    }
}
int main() {
    int length;
    cout << "Password Length: ";
    while(1) {
        cin >> length;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        else {
            break;
        }
    }
    passwordManager(length);
    return 0;
}
