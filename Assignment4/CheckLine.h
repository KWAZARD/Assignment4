#pragma once
#include <iostream>
#include "Line.h"
class CheckLine : public Line
{
	std::string item;
	bool checked;
public:
	CheckLine(bool ch, std::string& i) : item(i), checked(ch) {}
	void print() const override {
		std::cout << "[ " << (checked ? "x" : " ") << " ] " << item << std::endl;
	}
    virtual ~CheckLine() override {}

    void append(const std::string& t) override {
        item += t;
    }

    std::string getInfo() override {
        
        return "[ " + std::string(checked ? "x" : " ") + " ] " + item + "\n";
    }

    void insertAt(int pos, const std::string& t) override {
        if (pos <= item.length())
        {
            item.insert(pos, t);
        }
        else 
        {
            item += t;
        }
    }

    std::string serialize() const override {
        return "CHECKLIST|" + std::string(checked ? "1" : "0") + "|" + item;
    }
};