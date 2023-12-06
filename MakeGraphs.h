#include "VGData.h"
#pragma once

class MakeGraphs {
private:
    bool tryStod(const string& str, double& result);
public:
    void makeGenreBarChart(vector<VGData> records);
    void makePublisherBarChart(vector<VGData> records);
    void makeSalesScatter(vector<VGData> records);
    void printUniqueStrings(vector<string> uniqueStrings);
};

