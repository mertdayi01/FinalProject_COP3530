#include "MySetClass.h"
using namespace std;

void MySetClass::insert(const string& value) {
    // Check if the string is already in the set
    if (find(uniqueNames.begin(), uniqueNames.end(), value) == uniqueNames.end()) {
        uniqueNames.push_back(value);
    }
}

vector<string> MySetClass::getVector() {
    return uniqueNames;
}
