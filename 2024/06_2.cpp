#include <bits/stdc++.h>
using namespace std;

map<string, pair<int, int>> directionsDiff = {
    {"UP", {-1, 0}},
    {"DOWN", {1, 0}},
    {"RIGHT", {0, 1}},
    {"LEFT", {0, -1}},
};

string turnRight(string dir) {
    if (dir == "UP") return "RIGHT";
    if (dir == "RIGHT") return "DOWN";
    if (dir == "DOWN") return "LEFT";
    return "UP";
}

bool inGrid(int x, int y, vector<string> & grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
}

bool isWall(int x, int y, vector<string> & grid) {
    return inGrid(x, y, grid) && grid[x][y] == '#';
}

bool visitedCellWithSameDirection(int x, int y,  vector<vector<string>> & dirsInGrid, string currentDir) {
    string previousDir = dirsInGrid[x][y];
    return previousDir.size() >= currentDir.size() && previousDir.substr(0, currentDir.size()) == currentDir;
}

bool hasCycle(int x, int y, vector<string> & grid, vector<vector<string>> & dirsInGrid, string dir = "UP") {
    if (!inGrid(x, y, grid)) return false;

    if (visitedCellWithSameDirection(x, y, dirsInGrid, dir)) {
        return true;
    }
    dirsInGrid[x][y] += dir;
    grid[x][y] = 'X';

    auto [dx, dy] = directionsDiff[dir];
    int nextX = x + dx, nextY = y + dy;

    if (isWall(nextX, nextY, grid)) {
        dir = turnRight(dir);
    } else {
        x = nextX, y = nextY;
    }

    return hasCycle(x, y, grid, dirsInGrid, dir);
}

int main() {
    ifstream inputStream("input/06_2.txt");
    
    string inputLine;
    vector<string> grid;
    while (getline(inputStream, inputLine)) {
        grid.push_back(inputLine);
    }

    pair<int, int> guardPos;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[j].size(); j++) {
            if (grid[i][j] == '^')
                guardPos = {i, j};
        }
    }

    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != '.') continue;
            auto newGrid = grid;
            newGrid[i][j] = '#';
            vector<vector<string>> dirsInGrid(grid.size(), vector<string>(grid[j].size(), ""));
            res += hasCycle(guardPos.first, guardPos.second, newGrid, dirsInGrid);
        }
    }

    ofstream output("output/06_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}