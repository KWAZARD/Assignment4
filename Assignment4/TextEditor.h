#pragma once

#include <iostream>
#include <vector>
#include "Line.h"
class TextEditor
{
	std::vector<Line*> lines;
public:
	~TextEditor();
	void appendToEnd(std::string text);
	void insertAt(std::string text, int line, int pos);
	void addLine(Line* line);
	void printAll() const;
	std::string getAllSerealizedText() const;

	void clear();
	void deserialize(const std::string& decryptedData);
};

