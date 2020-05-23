
#include <iostream>
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")
#include "windows.h" 
#include <string>
#include <locale>         // std::locale, std::tolower
#include <direct.h>
#define cwd _getcwd
#define cd _chdir

using namespace std;

char buf[4096];

locale loc;
string c;
bool _WORKING_ = false;
string _USER_NAME_ = "root";
string _PASS_WORD_ = "toor";
string _USER_NAME_INPUT_;
string _PASS_WORD_INPUT_;
bool _LOGIN_ = true;
bool _DEBUG_ = true;



void start_text() {
    system("color 4");
    cout << "Starting MicheallesOS...";
    Sleep(500);
    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);
    printf("\n\nHardware information: \n\n");
    printf("OEM ID: %u\n", siSysInfo.dwOemId);
    printf("Number of processors: %u\n",
        siSysInfo.dwNumberOfProcessors);
    Sleep(500);
    printf("Page size: %u\n", siSysInfo.dwPageSize);
    printf("Processor type: %u\n", siSysInfo.dwProcessorType);
    printf("Minimum application address: %lx\n",
        siSysInfo.lpMinimumApplicationAddress);
    printf("Maximum application address: %lx\n",
        siSysInfo.lpMaximumApplicationAddress);
    Sleep(500);
    printf("Active processor mask: %u\n",
        siSysInfo.dwActiveProcessorMask);
    Sleep(1000);
    system("cls");
    Sleep(1000);
    system("color 7");
}

void login_in() {
    while (_LOGIN_ == true) {
        cout << "Welcome to MichealOS!" << endl;
        cout << "\nUserName: ";
        cin >> _USER_NAME_INPUT_;
        cout << "Password: ";
        system("color 0");
        cin >> _PASS_WORD_INPUT_;
        system("color 7");
        if (_USER_NAME_ == _USER_NAME_INPUT_ && _PASS_WORD_ == _PASS_WORD_INPUT_) {
            cout << "\nLoggined";
            Sleep(500);
            system("cls");
            _WORKING_ = true;
            _LOGIN_ = false;
        }
        else {
            system("cls");
            cout << "{Error UserName or Password}\n";
        }
    }
    system("color a");
}

int main()
{
    string command;

    if (_DEBUG_ == true) {
        _WORKING_ = true;
        _LOGIN_ = false;
        
    }
    else
    {
        start_text();
        login_in();
    }
    while (_WORKING_==true)
    {

        cout << _USER_NAME_ << "/~ ";
        getline(cin, command);
        cout << endl;
        c = "";
        for (auto elem : command)
            c+= tolower(elem, loc);
        command = c;
        if (command.find("exit") != string::npos) {
            cout << "Bey" << endl;
            _WORKING_ = false;
            system("pause");
        }
        else if (command.find("shell") != string::npos and command.find("shell python") == string::npos and command.find("shell help") == string::npos and command.find("shell cmd") == string::npos)
        {
            cout << "Help Shell: \n  [shell-help] - about command [shell] \n  [shell-python] - will start Python shell on your Computer.\n  But you need to install it, if you haven't done it before. Link: https://www.python.org/ \n  [shell-cmd] - will start Windows CMD on your Computer.\n\n";
            cout << "Write which one do you want to use!\n";
            cout << _USER_NAME_ << "/shell-";
            getline(cin, command);
            cout << endl;
            c = "";
            if (command.find("python") != string::npos)
            {
                system("python");
            }
            else if (command.find("help") != string::npos)
            {
                cout << "Help Shell: \n  [shell-help] - about command [shell] \n  [shell-python] - will start Python shell on your Computer.\n  But you need to install it, if you haven't done it before. Link: https://www.python.org/ \n  [shell-cmd] - will start Windows CMD on your Computer.\n\n";
            }
            else if (command.find("cmd") != string::npos)
            {
                system("cmd");
            }
            else {
                cout << "ERROR shell\n";
            }
        }
        else if (command.find("shell python") != string::npos)
        {
            system("python");
        }
        else if (command.find("shell help") != string::npos)
        {
            cout << "Help Shell: \n  [shell-help] - about command [shell] \n  [shell-python] - will start Python shell on your Computer.\n  But you need to install it, if you haven't done it before. Link: https://www.python.org/ \n  [shell-cmd] - will start Windows CMD on your Computer.\n\n";
        }
        else if (command.find("shell cmd") != string::npos)
        {
            system("cmd");
        }
        else if (command.find("cls") != string::npos or command.find("clear") != string::npos)
        {
            system("cls");
        }
        else if (command.find("ver") != string::npos)
        {
            cout << "\nMichealles Operating System v.0.0.1\n\nMicrosoft:";
            system("ver");
        }
        else if (command.find("cwd") != string::npos or command.find("path") != string::npos)
        {
            cout << cwd(buf, sizeof buf) << endl;
        }
        else if (command.find("cd ") != string::npos)
        {
            command = command.substr(3, command.length());
            cd(command.c_str());
        }
        else if (command.find("dir") != string::npos or command.find("ls") != string::npos)
        {
            system("dir");
        }
        else if (command.find("run ") != string::npos)
        {
            command = command.substr(4, command.length());
            system(command.c_str());
        }
        else
        {
            cout << command << " is the wrong command" << endl;
        }
        
    }
    
}
