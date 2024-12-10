#include <bits/stdc++.h>
using namespace std;

bool inBound(pair<int, int> coord, int n, int m) {
    return coord.first >= 0 && coord.first < n && coord.second >= 0 && coord.second < m;
}

vector<pair<int, int>> antinodes(pair<int, int> x, pair<int, int> y, int n, int m) {
    if (y.first < x.first)
        swap(x, y);
    
    int dx = y.first - x.first;
    int dy = y.second - x.second;

    pair<int, int> xAntinode = {x.first - dx, x.second - dy};
    pair<int, int> yAntinode = {y.first + dx, y.second + dy};

    vector<pair<int, int>> res;
    if (inBound(xAntinode, n, m))
        res.push_back(xAntinode);
    if (inBound(yAntinode, n, m))
        res.push_back(yAntinode);
    return res;
}

int main() {
    ifstream inputStream("input/08.txt");

    vector<string> grid;

    string inputLine;
    while (getline(inputStream, inputLine)) {
        grid.push_back(inputLine);
    }
    int n = grid.size(), m = grid[0].size();

    map<char, vector<pair<int, int>>> antenaGroups;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            antenaGroups[grid[i][j]].push_back({i, j});
        }
    }

    set<pair<int, int>> uniqueAntinodes;
    for (auto [antenna, coords] : antenaGroups) {
        for (int i = 0; i < coords.size(); i++) {
            for (int j = i + 1; j < coords.size(); j++) {
                for (auto antinode : antinodes(coords[i], coords[j], n, m)) {
                    uniqueAntinodes.insert(antinode);
                }
            }
        }
    }

    ofstream output("output/08.txt");
    cout.rdbuf(output.rdbuf());
    cout << uniqueAntinodes.size();
}