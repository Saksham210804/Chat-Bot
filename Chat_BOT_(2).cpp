// Chat_BOT_(2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <string.h>
#include <ctime>
#include <algorithm>
#include <sapi.h>
#include <stdio.h>
using namespace std;

int TEXT_TO_SPEECH(string str)
{
    if (FAILED(::CoInitialize(nullptr))) {
        cerr << "Failed to initialize COM library" << endl;
        return -1;
    }

    // Initialize SAPI
    ISpVoice* pVoice = nullptr;
    if (FAILED(::CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice))) {
        cerr << "Failed to create SAPI voice instance" << endl;
        ::CoUninitialize();
        return -1;
    }
    wstring wtext(str.begin(), str.end());

    // Speak the text
    pVoice->Speak(wtext.c_str(), SPF_IS_XML, nullptr);
}

int main()
{   
    
    cout << "Hiiiiiiii!!!!!!"<< endl;
    cout << "I am your personal assistant!!" << endl;
    cout << "Please type your query "<<endl;
    string str = "Hiiii, i am your personal assistant, Please type your query";
    TEXT_TO_SPEECH(str);
    char ques[100];
    
    while (true)
    {
        cout << "QUERY ------>  ";
        cin>>ques;
        if (strcmp(ques, "Hi") == 0 || strcmp(ques,"Hello") == 0 || strcmp(ques,"hello") == 0 || strcmp(ques,"hi") == 0 || strcmp(ques,"What's up") == 0)
        {
            cout << "Hi there, I am fine" << endl;
            string str = "Hi there, I am fine";
            TEXT_TO_SPEECH(str);
        }
        else if (strcmp(ques, "Who") == 0 || strcmp(ques, "What") == 0)
        {
            cout << "I am your personal assistant" << endl;
            string str2 = "I am your personal assistant";
            TEXT_TO_SPEECH(str2);
        }
        else if (strcmp(ques, "Time") == 0 || strcmp(ques, "date") == 0)
        {
            time_t TIME = time(0);
            cout << "Current date and time is:"<<endl;
            
                cout << TIME <<endl;
        }
        else if (strcmp(ques, "Notepad") == 0 || strcmp(ques, "document") == 0)
        {
            cout << "Opening Notepad....." << endl;
            string str3 = "Opening Notepad";
            TEXT_TO_SPEECH(str3);
            system("Notepad");
        }
        else if (strcmp(ques, "Google") == 0 || strcmp(ques, "browse") == 0 || strcmp(ques, "web") == 0)
        {
            cout << "Opening google web browser...." << endl;
            string str4 = "Opening google web browser";
            TEXT_TO_SPEECH(str4);
            system("Start https://www.google.co.in/");
        }
        else if (strcmp(ques, "Spotify") == 0 || strcmp(ques, "music") == 0 || strcmp(ques, "song") == 0)
        {
            cout << "Opening Spotify...." << endl;
            string str6 = "Opening Spotify";
            TEXT_TO_SPEECH(str6);
            system("Spotify.exe");
        }
        else if (strcmp(ques, "Bye") == 0 || strcmp(ques, "bye") == 0 || strcmp(ques, "quit") == 0 || strcmp(ques, "Quit") == 0)
        {
            cout << "Okay tell me if you neeed anything" << endl;
            cout << "Take care, Bye" << endl;
            string str7 = "Okay tell me if you neeed anything, Take care, Bye ";
            TEXT_TO_SPEECH(str7);
            break;
        }
        else
        {
            cout << "Sorry but i could not understand your question!!!!" << endl;
            string str5 = "Sorry but i could not understand your question";
            TEXT_TO_SPEECH(str5);
        }
    }
 
  



 

    


    

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
