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

void traverse(int x, int y, vector<string> & grid, string dir = "UP") {
    if (!inGrid(x, y, grid)) return;
    grid[x][y] = 'X';

    auto [dx, dy] = directionsDiff[dir];
    int nextX = x + dx, nextY = y + dy;

    if (isWall(nextX, nextY, grid)) {
        dir = turnRight(dir);
    } else {
        x = nextX, y = nextY;
    }

    traverse(x, y, grid, dir);
}

int main() {
    ifstream inputStream("input/06.txt");
    
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

    traverse(guardPos.first, guardPos.second, grid);

    int res = 0;
    for (string row : grid)
        for (char cell : row)
            if (cell == 'X')
                res++;

    ofstream output("output/06.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}