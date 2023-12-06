#include "MakeGraphs.h"
#include <vector>
#include <string>
#include <map>
#include "matplotlibcpp.h"
#include "MySetClass.h"
namespace plt = matplotlibcpp;
using namespace std;

void MakeGraphs::makeGenreBarChart(vector<VGData> records) {
    MySetClass uniqueGenreSet;

    vector<string> genres;
    vector<int> genreCounts;
    map<string, int> genreCount;

    for (const auto& record : records) {
        uniqueGenreSet.insert(record.genre);
        genreCount[record.genre]++;
    }
    for (const auto& genre : genreCount) {
        genreCounts.push_back(genre.second);
    }

    genres = uniqueGenreSet.getVector();
    printUniqueStrings(genres);

    plt::figure();
    plt::bar(genreCounts);
    plt::title("Genre Distribution");
    plt::xlabel("Genres");
    plt::ylabel("Count");
    //plt::show();
}

void MakeGraphs::makePublisherBarChart(vector<VGData> records) {
    MySetClass uniquePublisherSet;

    vector<string> publishers;
    vector<int> publisherCounts;
    map<string, int> publisherCount;

    for (const auto& record : records) {
        uniquePublisherSet.insert(record.publisher);
        publisherCount[record.publisher]++;
    }
    for (const auto& genre : publisherCount) {
        publisherCounts.push_back(genre.second);
    }

    publishers = uniquePublisherSet.getVector();
    printUniqueStrings(publishers);

    plt::figure();
    plt::bar(publisherCounts);
    plt::title("Publisher Distribution");
    plt::xlabel("Publishers");
    plt::ylabel("Count");
    //plt::show();
}

void MakeGraphs::makeSalesScatter(vector<VGData> records) {
    vector<double> naSales;
    vector<double> euSales;
    vector<double> jpSales;
    vector<double> otherSales;
    vector<double> years;

    for (const auto& record : records) {
        double year;
        if (tryStod(record.year, year)) {
            naSales.push_back(stod(record.naSales));
            euSales.push_back(stod(record.euSales));
            jpSales.push_back(stod(record.jpSales));
            otherSales.push_back(stod(record.otherSales));
            years.push_back(stod(record.year));
        }
    }

    plt::figure();
    plt::scatter(years, naSales);
    plt::scatter(years, euSales);
    plt::scatter(years, jpSales);
    plt::scatter(years, otherSales);

    plt::text(years.front(), *std::max_element(naSales.begin(), naSales.end()), "NA Blue");
    plt::text(years.front(), *std::max_element(euSales.begin(), euSales.end()) + 10, "EU Orange");
    plt::text(years.front(), *std::max_element(jpSales.begin(), jpSales.end()) + 26, "JP Green");
    plt::text(years.front(), *std::max_element(otherSales.begin(), otherSales.end()) + 23, "Other Red");

    plt::xlabel("Year");
    plt::ylabel("Sales (Millions)");
    plt::title("Sales Comparison Across Regions");

}

bool MakeGraphs::tryStod(const std::string& str, double& result) {
    try {
        result = stod(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

void MakeGraphs::printUniqueStrings(vector<std::string> uniqueStrings) {
    for (int i = 0; i < uniqueStrings.size(); i++) {
        cout << i << ": " << uniqueStrings.at(i) << endl;
    }
    cout << endl;
}