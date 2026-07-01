#pragma once
#include <iostream>

class ComandLineInterface
{
public: 
	void writeToFile(const std::string& path, const std::string& data);
	std::string loadFromFile(const std::string& path);

	void run();
};

