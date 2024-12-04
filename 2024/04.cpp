#include <bits/stdc++.h>
using namespace std;

bool horizontalMatch(int row, int col, string & word, vector<string> & grid) {
    for (char ch : word) {
        if (col >= grid[row].size() || grid[row][col] != ch)
            return false;
        col++;
    }
    return true;
}

bool verticalMatch(int row, int col, string & word, vector<string> & grid) {
    for (char ch : word) {
        if (row >= grid.size() || grid[row][col] != ch)
            return false;
        row++;
    }
    return true;
}

int diagonalMatchCount(int startRow, int startCol, string & word, vector<string> & grid) {
    // direction: right down
    int rightDownMatch = 1;
    int row = startRow, col = startCol;
    for (char ch : word) {
        if (row >= grid.size() || col >= grid[row].size() || grid[row][col] != ch) {
            rightDownMatch = 0;
            break;
        }
        row++; col++;
    }
    // direction: left down
    int leftDownMatch = 1;
    row = startRow;
    col = startCol;
    for (char ch : word) {
        if (row < 0 || col >= grid[row].size() || grid[row][col] != ch) {
            leftDownMatch = 0;
            break;
        }
        row--; col++;
    }
    return rightDownMatch + leftDownMatch;
}

int searchWordInGrid(string word, vector<string> & grid) {
    int matchCount = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (horizontalMatch(i, j, word, grid))
                matchCount++;
            if (verticalMatch(i, j, word, grid))
                matchCount++;
            matchCount += diagonalMatchCount(i, j, word, grid);
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

    int res = searchWordInGrid("XMAS", grid) + searchWordInGrid("SAMX", grid);

    ofstream output("output/04.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}