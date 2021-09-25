// @file authenticator.cpp
// @brief This program takes a three character input and compares it to a pre-existing code
// @author Aiden White aiwhite@chapman.edu

#include <iostream>
#include <string>
using namespace std;


int main()
{
    // Part 1
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    char userInputChar1;
    char userInputChar2;
    char userInputChar3;
    string AuthenticatorCodeComplete = "";
    string userCodeComplete = "";

    cout << "Enter the first character of the message code:" << endl;
    cin >> userInputChar1;
    cout << "Enter the second character of the message code:" << endl;
    cin >> userInputChar2;
    cout << "Enter the third character of the message code:" << endl;
    cin >> userInputChar3;

    AuthenticatorCodeComplete += k_cAuthenticatorCodeCharacter1;
    AuthenticatorCodeComplete += k_cAuthenticatorCodeCharacter2;
    AuthenticatorCodeComplete += k_cAuthenticatorCodeCharacter3;

    userCodeComplete += userInputChar1;
    userCodeComplete += userInputChar2;
    userCodeComplete += userInputChar3;

    cout << "Authenticator Code: " << AuthenticatorCodeComplete << endl;
    cout << "Message Code: " << userCodeComplete << endl;

    // Part 2
    bool codesMatch = false;

    if ((AuthenticatorCodeComplete.at(0) == userCodeComplete.at(0)) &&
        (AuthenticatorCodeComplete.at(1) == userCodeComplete.at(1)) &&
        (AuthenticatorCodeComplete.at(2) == userCodeComplete.at(2))
        )
    {
        codesMatch = true;
    }

    if (codesMatch)
    {
        cout << "Message is authentic." << endl;
    }
    else
    {
        cout << "Message is invalid." << endl;
    }

    // Part 3
    if (AuthenticatorCodeComplete == userCodeComplete)
    {
        cout << "Concurrence: message is authentic." << endl;
    }
    else
    {
        cout << "Concurrence: message is invalid." << endl;
    }

    // Part 4
    const int k_iValidCodeChecksum = 5;

    int checksum = (int(userInputChar1) + int(userInputChar2) + int(userInputChar3)) % 7;

    cout << "Characterization of Message Code" << endl << "------------------------------" << endl;

    if (checksum == k_iValidCodeChecksum)
    {
        cout << "Message Code Checksum is valid: 5" << endl;
    }
    else
    {
        cout << "Message Code Checksum is invalid: " << checksum << " expected: 5" << endl;
    }

    cout << "ASCII Values of Message Code Characters: " << int(userInputChar1) << ", " <<
        int(userInputChar2) << ", " << int(userInputChar3) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << int(userInputChar1) +
        int(userInputChar2) + int(userInputChar3) << endl;

    if (AuthenticatorCodeComplete.at(0) != userCodeComplete.at(0))
    {
        cout << "First characters do not match: Message: " << userCodeComplete.at(0) <<
            " Authenticator: " << AuthenticatorCodeComplete.at(0) << endl;
    }
    if (AuthenticatorCodeComplete.at(1) != userCodeComplete.at(1))
    {
        cout << "Second characters do not match: Message: " << userCodeComplete.at(1) <<
            " Authenticator: " << AuthenticatorCodeComplete.at(1) << endl;
    }
    if (AuthenticatorCodeComplete.at(2) != userCodeComplete.at(2))
    {
        cout << "Third characters do not match: Message: " << userCodeComplete.at(2) <<
            " Authenticator: " << AuthenticatorCodeComplete.at(2) << endl;
    }

    if (!codesMatch)
    {
        if (userCodeComplete < AuthenticatorCodeComplete)
        {
            cout << "Message code (" << userCodeComplete << ") is lexicographically less than Authentiactor code (" <<
                AuthenticatorCodeComplete << ")" << endl;
        }
        else
        {
            cout << "Message code (" << userCodeComplete << ") is lexicographically greater than Authentiactor code (" <<
                AuthenticatorCodeComplete << ")" << endl;
        }
    }

    return 0;
}

