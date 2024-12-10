#include <bits/stdc++.h>
using namespace std;

bool matches(int dx, int dy, int x, int y, string word, vector<string> & grid) {
    if (word.empty())
        return true;
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size())
        return false;
    return word[0] == grid[x][y] && matches(dx, dy, x + dx, y + dy, word.substr(1), grid);
}

int searchWordInGrid(string word, vector<string> & grid) {
    int matchCount = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            // search in 8 directions from the (i, j): + and x
            vector<pair<int, int>> dirs = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}, // right, left, down, up
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // diagonal directions
            };
            for (auto [dx, dy] : dirs) {
                matchCount += matches(dx, dy, i, j, word, grid);
            }
        }
    }
    return matchCount;
}

int main() {
    ifstream inputStream("input/04.txt");
    
    string inputLine;
    vector<string> grid;
    while (getline(inputStream, inputLine)) {
        grid.push_back(inputLine);        
    }

    ofstream output("output/04.txt");
    cout.rdbuf(output.rdbuf());
    cout << searchWordInGrid("XMAS", grid);
}
