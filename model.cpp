#include "fileintegritychecker.h"
#include <iostream>
#include <fstream>

using namespace std;

FileIntegrityChecker::FileIntegrityChecker(const string &path)
{
    filePath = path; //example.txt
    string content = readFileContents();
    originalHash = simpleHash(content);
    cout << "Original hash saved." << endl;
}

string FileIntegrityChecker::readFileContents()
{
    ifstream file(filePath);
    if (!file)
    {
        cerr << "Error: Cannot open file." << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

int FileIntegrityChecker::simpleHash(const string &data)
{
    int hash = 0;
    for (char c : data)
    {
        hash += static_cast<int>(c); // ASCII sum hash
    }
    return hash;
}

void FileIntegrityChecker::checkIntegrity()
{
    string content = readFileContents(); //string
    int currentHash = simpleHash(content);

    cout << "Stored Hash:  " << originalHash << endl;
    cout << "Current Hash: " << currentHash << endl;

    if (currentHash == originalHash)
    {
        cout << "File is unchanged." << endl;
    }
    else
    {
        cout << "File has been modified!" << endl;
    }
}
