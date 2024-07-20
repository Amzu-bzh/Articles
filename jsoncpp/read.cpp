/// \file		read.cpp
/// \author		@Amzu-bzh
/// \project	articles/jsoncpp

#include <iostream>
#include <json/json.h>
#include <fstream>

int read()
{
	// Read a JSON file
	std::ifstream iFile("people.json");

	Json::Reader reader;
	Json::Value iRoot;

	reader.parse(iFile, iRoot);
	iFile.close();

	std::cout << "Hi ! My name is " << iRoot["firstname"].asString() << " " << iRoot["lastname"].asString() << std::endl;
	std::cout << "I'm " << iRoot["age"].asString() << " and I live in " << iRoot["adress_city"].asString() << std::endl;

	std::cout << "I'm a " << iRoot["job"]["description"].asString() << " in " << iRoot["job"]["adress"].asString() << std::endl;
	iRoot.clear();

	system("pause");
	system("cls");

	return EXIT_SUCCESS;
}