#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>
using namespace std;

void registration(string username, string password) {
    bool found=false;
    string uname;

    ifstream obj("all_uname.txt");
    while(obj>>uname) {
        if(uname==username) {
            found=true;
            break;
        }
    }
    obj.close();
    if(found) {
        cout<<"This username is already exist...\n";
    } else {

        ofstream ob("all_uname.txt", ios::app);
        ob<<username<<endl;
        ob.close();

        string file = username + ".txt";
        ofstream fout(file);

        fout<<username<<endl;
        fout<<password;

        fout.close();
        cout<<"\nYou are successfully registered..!!!\n";
    }
}

void login(string username, string password) {
    string uname;
    string pass;

    string file = username + ".txt";
    ifstream fin(file);
    getline(fin, uname);
    getline(fin, pass);

    if(uname==username && pass==password) {
        cout<<"\n\nLogin successful..!!!\n";
    } else {
        cout<<"\n\nInvalid username or password\n";
    }
}

int main() {
    cout<<"\n||| WELCOME TO LOGIN & REGISTRATION SYSTEM |||\n\n";
    string username, password;
    char c;
    int ch;
    do {
        cout<<"Select operation\n1. Registration\n2. Login\n0. Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch) {
            case 1:
                cout<<"Enter username : ";
                cin>>username;
            
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout<<"Enter password : ";
                getline(cin, password);

                registration(username, password);
                break;
            case 2:
                cout<<"Enter username : ";
                cin>>username;
            
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout<<"Enter password : ";
                password="";
                while((c=_getch()) != 13) {
                    if(c == 8) {
                        if(password.length() > 0) {
                            password.pop_back();
                            cout << "\b \b";
                        }
                    } else {
                        password += c;
                        cout << "*";
                    }
                }
                cout<<endl;
                login(username, password);
                break;
            case 0:
                cout<<"\nExiting the program..!!!\n";
                break;
            default:
                cout<<"Please select valid choice\n";
        }
    }while(ch!=0);

    cout<<"\n Developed by PARTH\n\n";
    return 0;
}