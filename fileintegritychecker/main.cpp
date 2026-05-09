#include "fileintegritychecker.h"
#include <iostream>

using namespace std;

int main()
{
    string path = "example.txt"; // Replace with your file

    FileIntegrityChecker checker(path);

    cout << "Modify the file if you want.\n";
    cout << "Press Enter to check integrity again...\n";
    cin.get();

    checker.checkIntegrity();

    system("pause");

    return 0;
}
