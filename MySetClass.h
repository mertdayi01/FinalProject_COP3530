#include <vector>
#include <string>
using namespace std;
#pragma once


class MySetClass {
private:
    vector<string> uniqueNames;
public:
    void insert(const string& value);
    vector<string> getVector();
};

