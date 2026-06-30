// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <stdbool.h>
#include "Functions.h"




//===========================================MAIN===================================================================================


static std::list<char> char_list;

int line = -1;
int index = -1;

int main()
{

    
    printf("1-Append text symbols to the end\n"
        "2-Start the new line\n"
        "3-Print the current text to console\n"
        "4-Insert the text by line and symbol index\n"
        "5-Search(please note that the text can be found more than once)\n"
        "6-Use files to load the information\n"
        "7-Use files to save the information\n"
        "8-Delete from position\n"
        "9-Undo\n"
        "10-Redo\n"
        "11-Copy\n"
        "12-Cut\n"
        "13-Paste\n"
        "14-Insert with replacement\n"
        "15-Cursor placement\n"
        "15-Finish program\n"
        ">Choose options\n");



    int user_choise;
    while (true)
    {
        printf(">");

        
        std::cin >> user_choise;
        
        switch (user_choise)
        {
        case 1:
            AppendTextToEnd(&char_list);
            
            break;
        case 2:
            StartNewLine(&char_list);
            break;
        case 3:
            PrintAllText(&char_list);
            break;
        case 4:
            InsertAtPosition(&char_list);
            break;
        case 5:

            break;
        case 6:
            
            break;
        case 7:
           
            break;

        case 8:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            
            int length;

           
            break;
        }
        case 9:
        {

            


            break;
        }
        case 10:
        {
            


            break;
        }
        case 11:
        {
            
            break;
        }
        case 12:
        {
            break;
        }
        case 13:
        {
            
            break;
        }
        case 14:
        {
           
            break;

        }
        case 15:
            
            break;
        case 16:
            
            std::cout << "Program is finished\n";
            return 0;
        default:
            std::cout << ">This command is not valid. Please enter normal number (1-16)\n";
            break;

        }
    }

    return 0;
}



