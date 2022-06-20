#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace mu {

	class Menu
	{
	public:
		string nCharString(size_t t_n, char t_c);
		void printMenu();
		string getUserQuery();
		void genHistogram(string filePath);

	};


}

