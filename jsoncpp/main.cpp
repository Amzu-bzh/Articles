/// \file		main.cpp
/// \author		@Amzu-bzh
/// \project	articles/jsoncpp

#include <iostream>
#include <json/json.h>
#include <fstream>

int main()
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

	// Write a JSON file
	Json::Value oRoot;

	oRoot["title"] = "Ariane 6 - The future of european space";
	oRoot["author"] = "Amaury GODOT";
	oRoot["link"] = "amaury-godot.medium.com/ariane-6-the-future-of-european-space-7a3ad85c3c29";

	Json::StyledWriter styledWriter;
	Json::FastWriter fastWriter;

	std::string content = styledWriter.write(oRoot);
	std::cout << "Styled writer :" << std::endl << content << std::endl;

	content = fastWriter.write(oRoot);
	std::cout << "Fast writer :" << std::endl << content << std::endl;

	std::ofstream oFile("web_page.json");
	oFile << content;
	oFile.close();

	oRoot.clear();
	styledWriter.~StyledWriter();
	fastWriter.~FastWriter();

	system("pause");
	system("cls");

	return EXIT_SUCCESS;
}