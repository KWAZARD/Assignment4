#include "ComandLineInterface.h"
#include <fstream>
#include <string>
#include "TextEditor.h"
#include <iostream>
#include "TextLine.h"
#include "CheckLine.h"
#include "ContactInfo.h"
#include "Line.h"
#include "Cipher.h"

std::string ComandLineInterface::loadFromFile(const std::string& path)
{
    std::ifstream inFile(path);

    if (!inFile.is_open()) {
        std::cout << "Error opening file!\n";
        return "";
    }

    std::string content;
    std::string line;
    

    while (std::getline(inFile, line)) {
        content += line + "\n";
    }
    inFile.close();
    return content;
}

void ComandLineInterface::writeToFile(const std::string& path, const std::string& data)
{
    std::ofstream outFile(path);

    if (!outFile.is_open()) {
        std::cout << "Error opening file!\n";
        
    }
    outFile << data;
 
    outFile.close();
}

void ComandLineInterface::run()
{
    TextEditor textEditor;
    int user_choice;

    while (true)
    {
        printf("1-Append to end\n2-Add new line\n3-Print all lines\n4-Insert at possition\n5-Write to file\n6-Load from file\n>");
        std::cin >> user_choice;

        switch (user_choice)
        {
        case 1:
        {
            std::cin.ignore();
            printf("Append text symbols to the end:\n>");
            std::string text;
            std::getline(std::cin, text);
            textEditor.appendToEnd(text);
            break;
        }
        case 2:
        {
            std::cin.ignore();
            int choice;
            std::cout << "Type of line which you add: (1-Text Line or 2-CheckList Line or 3-ContactInfo line)\n>";
            std::cin >> choice;

            if (std::cin.fail())
            {
                std::cin.clear(); 
                

                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                std::cout << "Error: Invalid command\n";

                continue;
            }
            switch (choice)
            {
            case 1:
            {
                std::cin.ignore();
                printf("Enter your text:\n>");
                std::string text;
                std::getline(std::cin, text);
                textEditor.addLine(new TextLine(text));
                break;
            }
            case 2:
            {
                std::cin.ignore();
                int checked;
                std::cout << "Is it done? (1-yes, 2-no)\n>";
                std::cin >> checked;

                std::cin.ignore();
                printf("Enter your text:\n>");
                std::string text;
                std::getline(std::cin, text);
                textEditor.addLine(new CheckLine(checked, text));
                break;
            }
            case 3:
            {
                std::cin.ignore();
                printf("Enter name:\n>");
                std::string name;
                std::getline(std::cin, name);
                printf("Enter email:\n>");
                std::string email;
                std::getline(std::cin, email); 
                textEditor.addLine(new ContactInfo(name, email));
                break;
            }
            default:
                std::cout << "Invalid command\n";
                break;
            }
            break;
        }
        case 3:
        {
            textEditor.printAll();
            break;
        }
        case 4:
        {
            std::cin.ignore();
            int line;
            int position;
            std::cout << "Enter line and position\n>";
            std::cin >> line >> position;
            std::cin.ignore();
            printf("Write text to insert:\n>");
            std::string text;
            std::getline(std::cin, text);
            textEditor.insertAt(text, line, position);
            break;
        }
        case 5:
        {
            std::cin.ignore();
            Cipher cipher;

            if (!cipher.loadLibrary())
            {
                std::cout << "Dll was not loaded successfully";
                break;
            }

            std::string resultText = cipher.Encrypt(textEditor.getAllSerealizedText());
            writeToFile("Assignment4.txt", resultText);
            break;
        }
        case 6:
        {
            std::cin.ignore();
            Cipher cipher;

            if (!cipher.loadLibrary())
            {
                std::cout << "Dll was not loaded successfully";
                break;
            }
            

            std::string loadText = loadFromFile("Assignment4.txt");
            std::string decryptedText = cipher.Decrypt(loadText);
            textEditor.deserialize(decryptedText);
            break;
        }
        default:
            std::cout << "Comand does not exist\n";
            break;
        } 
    } 
} 