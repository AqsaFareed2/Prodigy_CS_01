#include <iostream>
#include <string>
using namespace std;

string result; // Global variable to store the result
char temp; // Temporary variable for character manipulation

// Function to perform encryption using Caesar cipher
string encrypt(string text, int shift)
{
    result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i])) { // Check if it's an alphabetic character
            // Preserve case while encrypting
            if (isupper(text[i]))
                result += ((text[i] - 'A' + shift) % 26) + 'A';
            else
                result += ((text[i] - 'a' + shift) % 26) + 'a';
        }
        else {
            result += text[i]; // Non-alphabetic characters remain unchanged
        }
    }
    return result;
}

// Function to perform decryption using Caesar cipher
string decrypt(string text, int shift)
{
    result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i])) { // Check if it's an alphabetic character
            // Preserve case while decrypting
            if (isupper(text[i]))
                result += ((text[i] - 'A' - shift + 26) % 26) + 'A';
            else
                result += ((text[i] - 'a' - shift + 26) % 26) + 'a';
        }
        else {
            result += text[i]; // Non-alphabetic characters remain unchanged
        }
    }
    return result;
}


int main()
{
    string inputText, userChoice; // Variables to store user input
    int shift; // Variable to store the encryption/decryption key
    char option; // Variable to store user's choice to continue or not

    do {
        // Prompt the user to choose encryption or decryption
        cout << "Press 'E' to encrypt and 'D' to decrypt" << endl;
        cin >> userChoice;

        cout << "Enter text: " << endl;
        cin >> inputText;

        cout << "Enter shift: " << endl;
        cin >> shift;

        // Switch statement to perform encryption or decryption based on user input
        switch (userChoice[0])
        {
        case 'E':
        case 'e':
            cout << "Encrypted text: " << endl << encrypt(inputText, shift) << endl;
            break;
        case 'D':
        case 'd':
            cout << "Decrypted text: " << endl << decrypt(inputText, shift) << endl;
            break;
        default:
            cout << "Invalid input" << endl;
        }

        cout << "Do you want to continue? (Press 'Y' for yes, 'N' for no): ";
        cin >> option;
    } while (option == 'Y' || option == 'y');

    return 0;
}
