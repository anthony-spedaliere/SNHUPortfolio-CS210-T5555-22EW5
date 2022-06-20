#include "Menu.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <vector>


using namespace std;
using namespace mu;


/*
 * Returns a string of length t_n, each character a t_c.
 * For example, nCharString(5, '*') should return "*****"
 *
 * @param t_n string length, >=0
 * @param any character t_c to output t_n times
 *
 * @return string of t_n t_c's
 */

string Menu::nCharString(size_t t_n, char t_c) {

    string charString = "";

    if (t_n >= 0) {
        for (int i = 0; i < t_n; ++i) {
            charString = charString + t_c;
        }
        return charString;
    }

    if (t_n < 0) {
        throw runtime_error("Input must be greater than 0.");
    }

}


/*
 * Outputs the dipslay for the user interface for data input
 *
 * @return void
 */

void Menu::printMenu() {
    cout << nCharString(49, '*') << endl;
    cout << nCharString(10, '*') << "Corner Grocer Analyzer Tool" << nCharString(12, '*') << endl;
    cout << "1: Print Daily Purchases" << endl;
    cout << "2: Search Items Purchased" << endl;
    cout << "3: Print Histogram" << endl;
    cout << "4: Exit" << endl;
    cout << "Enter your selection as a number 1, 2, 3, or 4." << endl;
    cout << endl;
}

/*
 * Get user input
 *
 * @return void
 */

string Menu::getUserQuery() {
    
    string userQuery;

    cout << "Please enter your query: ";

    cin >> userQuery;

    return userQuery;
  
}



/*
 * Read frequency.dat file and display histogram
 *
 * @params string of file name or file path
 *
 * @return void
 */

void Menu::genHistogram(string filePath) {
    
    //instantiate file stream variable
    ifstream inFS;

    //open DAT file
    inFS.open("frequency.dat");

    // error handling
    if (!inFS.is_open()) {
        cout << "Could not open the file." << endl;
    }

    // read data
    string s;
    vector<string> dataVector;

    while (inFS >> s) {

        dataVector.push_back(s);

    }
    
    // generate histogram

    cout << "===HISTOGRAM===" << endl;
    
    for (int i = 0; i < dataVector.size(); i = i + 2) {
        
        cout << dataVector.at(i) << " ";

        for (int j = 0; j < stoi(dataVector.at(i + 1)); ++j) {
            cout << "*";
        }

        cout << endl;

    }

    // close the file
    inFS.close();

}