#pragma once
#include <iostream>
class Line
{
public:
	virtual void print() const = 0;
    virtual ~Line() {}


    virtual void append(const std::string& t) = 0;
    virtual void insertAt(int pos, const std::string& t) = 0;
    virtual std::string getInfo() = 0;

    
    virtual std::string serialize() const = 0;


};

