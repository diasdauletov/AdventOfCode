#include <bits/stdc++.h>
using namespace std;

int computeScore(int x, int y, vector<string> & grid, char prev = '/') {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size())
        return 0;
    if (prev + 1 != grid[x][y]) 
        return 0;
    
    if (grid[x][y] == '9') {
        grid[x][y] = 'X';
        return 1;
    }
    int res = 0;
    vector<pair<int, int>> diff = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto [dx, dy] : diff) {
        res += computeScore(x + dx, y + dy, grid, grid[x][y]);
    }
    return res;
}

int main() {
    ifstream inputStream("input/10.txt");
    
    vector<string> grid;

    string inputLine;
    while(getline(inputStream, inputLine)) {
        grid.push_back(inputLine);
    }
    
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != '0') continue;
            auto copied = grid;
            res += computeScore(i, j, copied);
        }
    }

    ofstream output("output/10.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}