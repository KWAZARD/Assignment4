#pragma once
#include <iostream>
#include "Line.h"

class ContactInfo : public Line
{
	std::string full_name;
	std::string email;
public:
	ContactInfo(std::string& fn, std::string& em) : full_name(fn), email(em) {}

    virtual ~ContactInfo() override {}
	void print() const override {
		std::cout << "Contact - " << full_name << ", Email: " << email << std::endl;
	}


    void append(const std::string& t) override {
        full_name += t;
    }

    std::string getInfo() override {
        return "Contact - " + full_name + ", Email: " + email + "\n";
    }

    void insertAt(int pos, const std::string& t) override {
        if (pos <= full_name.length())
        {
            full_name.insert(pos, t);
        }
        else
        {
            full_name += t;
        }
    }

    std::string serialize() const override {
        return "CONTACTINFO|" + full_name + "|" + email;
    }
};