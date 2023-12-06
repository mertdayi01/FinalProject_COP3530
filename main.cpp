#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "VGData.h"
#include "matplotlibcpp.h"
#include "MakeGraphs.h"
using namespace std;
namespace plt = matplotlibcpp;

int main() {
    vector<VGData> records; // Store the imported data

    // Open the CSV file
    ifstream inputFile("vgsales.csv");

    if (!inputFile.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;

        VGData vgData; // Create a new record for each line in the CSV

        getline(ss, vgData.rank, ',');
        getline(ss, vgData.name, ',');
        getline(ss, vgData.platform, ',');
        getline(ss, vgData.year, ',');
        getline(ss, vgData.genre, ',');
        getline(ss, vgData.publisher, ',');
        getline(ss, vgData.naSales, ',');
        getline(ss, vgData.euSales, ',');
        getline(ss, vgData.jpSales, ',');
        getline(ss, vgData.otherSales, ',');
        getline(ss, vgData.globalSales, ',');

        records.push_back(vgData); // Store the record in the vector
    }

    inputFile.close();
    records.erase(records.begin());
    records.erase(records.begin());

    cout << "Video Game Data" << endl;
    cout << "Choose What You Would Like To See And Press Done To See All" << endl;

    int exitLoop = 0;
    MakeGraphs graphMaker;

    while (exitLoop != 1) {
        cout << "1. Genre Bar Chart" << endl;
        cout << "2. Publisher Bar Chart" << endl;
        cout << "3. Region Sales Scatter Plot" << endl;
        cout << "4. Done" << endl;


        int userNum = 0;
        cin >> userNum;
        if (userNum == 1) {
            graphMaker.makeGenreBarChart(records);
        }
        else if (userNum == 2) {
            graphMaker.makePublisherBarChart(records);
        }
        else if (userNum == 3) {
            graphMaker.makeSalesScatter(records);
        }
        else if (userNum == 4) {
            exitLoop = 1;
        }
    }

    plt::show(); // When show inside graph function you have to close the current graph for next to load.


    return 0;
}
