/// \file		write.cpp
/// \author		@Amzu-bzh
/// \project	articles/jsoncpp

#include <iostream>
#include <json/json.h>
#include <fstream>

int write()
{
	Json::Value oRoot;

	oRoot["title"] = "Ariane 6 - The future of european space";
	oRoot["author"] = "Amaury GODOT";
	oRoot["link"] = "amaury-godot.medium.com/ariane-6-the-future-of-european-space-7a3ad85c3c29";

	Json::StyledWriter styledWriter;
	Json::FastWriter fastWriter;

	std::string styledContent = styledWriter.write(oRoot);
	std::cout << "Styled writer :" << std::endl << styledContent << std::endl;

	std::string fastContent = fastWriter.write(oRoot);
	std::cout << "Fast writer :" << std::endl << fastContent << std::endl;

	std::ofstream oFile("article.json");
	oFile << styledContent;
	oFile.close();

	oRoot.clear();
	styledWriter.~StyledWriter();
	fastWriter.~FastWriter();

	system("pause");
	system("cls");

	return EXIT_SUCCESS;
}