#pragma once
#include "Line.h"
#include <iostream>
class TextLine : public Line
{
	std::string text;
public:
	TextLine(const std::string& t) : text(t) {

	}
	void print() const override {
		std::cout << "Text: " << text << std::endl;
	}
	
    void append(const std::string& t) override {
        text += t;
    }

    void insertAt(size_t pos, const std::string& t) override {
        if (pos <= text.length()) text.insert(pos, t);
        else text += t;
    }

    std::string serialize() const override {
        return "TEXT|" + text;
    }

};

