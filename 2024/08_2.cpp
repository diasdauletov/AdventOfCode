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
    vector<pair<int, int>> res;

    pair<int, int> xAntinode = {x.first, x.second};
    while (inBound(xAntinode, n, m)) {
        res.push_back(xAntinode);
        xAntinode.first -= dx;
        xAntinode.second -= dy;
    }

    pair<int, int> yAntinode = {y.first, y.second};
    while (inBound(yAntinode, n, m)) {
        res.push_back(yAntinode);
        yAntinode.first += dx;
        yAntinode.second += dy;
    }
    return res;
}

int main() {
    ifstream inputStream("input/08_2.txt");

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

    ofstream output("output/08_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << uniqueAntinodes.size();
}