#include "TextEditor.h"
#include <string>
#include "Line.h"
#include "TextLine.h"
#include "CheckLine.h"
#include "ContactInfo.h"
#include <iostream>
#include <sstream>


TextEditor::~TextEditor() {
    for (size_t i = 0; i < lines.size(); ++i) {
        delete lines[i];
    }
}
void TextEditor::appendToEnd(std::string text)
{
    if (lines.empty())
    {
        std::cout << "Cannot append to null line!!!!!!!!\n";
        return;
    }
    lines.back()->append(text);
}
void TextEditor::insertAt(std::string text, int line, int pos)
{
    if (line < lines.size())
    {
        lines[line]->insertAt(pos, text);
    }
    else {
        std::cout << "There is no such line\n";
    }

    
}
void TextEditor::addLine(Line* line) {

    lines.push_back(line);
}


void TextEditor::printAll() const {
    for (size_t i = 0; i < lines.size(); ++i) {
        lines[i]->print();
    }
}


void TextEditor::clear() {
    for (size_t i = 0; i < lines.size(); ++i) {
        delete lines[i]; 
    }
    lines.clear();
}

std::string TextEditor::getAllSerealizedText() const
{
    std::string allText;
    for (size_t i = 0; i < lines.size(); ++i) {
        
        allText += lines[i]->serialize() + "\n";
    }
    return allText;
}

void TextEditor::deserialize(const std::string& decryptedData)
{
    clear();

    std::stringstream ss(decryptedData);
    std::string rawLine;

    while (std::getline(ss, rawLine)) {
        if (rawLine.empty()) continue;

        std::stringstream lineStream(rawLine);
        std::string type;
        std::getline(lineStream, type, '|'); 



        if (type == "TEXT") {
            std::string content;
            std::getline(lineStream, content);
            lines.push_back(new TextLine(content));
        }
        else if (type == "CHECKLIST") {
            std::string checkedStr;
            std::string content;
            std::getline(lineStream, checkedStr, '|');
            std::getline(lineStream, content);

            lines.push_back(new CheckLine(checkedStr == "1", content));
        }
        
        else if (type == "CONTACTINFO") {
            std::string name;
            std::string email;

            std::getline(lineStream, name, '|'); 
            std::getline(lineStream, email);    

            lines.push_back(new ContactInfo(name, email));
        }
    }
}

