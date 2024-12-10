#include <bits/stdc++.h>
using namespace std;

vector<string> customSort(vector<string> pages, map<string, set<string>> rule) {
    vector<string> res = pages;
    for (int i = 0; i < res.size(); i++) {
        for (int j = i + 1; j < res.size(); j++) {
            if (rule[res[j]].find(res[i]) != rule[res[j]].end()) {
                swap(res[i], res[j]);
            }
        }
    }
    return res;
}

int main() {
    ifstream inputStream("input/05.txt");
    
    string inputLine;
    map<string, set<string>> rule;
    while (getline(inputStream, inputLine) && inputLine[0] >= '0' && inputLine[0] <= '9') {
        string x = inputLine.substr(0, 2);
        string y = inputLine.substr(3, 2);
        rule[x].insert(y);
    }
    int res = 0;
    while (getline(inputStream, inputLine)) {
        vector<string> pages; 
        for (int i = 0; i < inputLine.size(); i += 3) {
            pages.push_back(inputLine.substr(i, 2));
        }

        auto sorted = customSort(pages, rule);
        if (sorted == pages) {
            res += stoi(sorted[sorted.size() / 2]);
        }
    }

    ofstream output("output/05.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}