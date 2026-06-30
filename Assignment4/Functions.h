#ifndef FUNCTIONS_H
#define FUNCTIONS_H



#include <string.h>
#include <stdbool.h>
#include <list>
#include <iostream>



void AppendTextToEnd(std::list<char>* char_list);
void StartNewLine(std::list<char>* head);
void PrintAllText(std::list<char>* head);
void InsertAtPosition(std::list<char>* head);
void CaseFive(std::list<char>* head);
void SaveFile(std::list<char>* head);
std::list<char>* LoadFile();



std::list<char>* DeleteCase(std::list<char>* head, int line, int index, int deleteNumber);
void Copy(std::list<char>*  head, int line, int index, int length);
std::list<char>* PasteInsertion(std::list<char>* head, std::list<char>* insertedHead, int line, int index);
std::list<char>* InsertWithReplasement(std::list<char>* head, int line, int index);
void SaveWithName(char fileName[], std::list<char>* head);
std::list<char>* LoadWithName(char fileName[]);



#endif

