#ifndef FILEINTEGRITYCHECKER_H
#define FILEINTEGRITYCHECKER_H

#include <string>
using namespace std;

class FileIntegrityChecker 
{
private:
    string filePath;
    int originalHash;

    string readFileContents();
    int simpleHash(const string& data);

public:
    FileIntegrityChecker(const string& path);
    void checkIntegrity();
};

#endif
