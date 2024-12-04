#include <bits/stdc++.h>
using namespace std;

bool isXMAS(string word) {
    return word == "MAS" || word == "SAM";
}

int main() {
    ifstream inputStream("input/04_2.txt");
    
    string inputLine;
    vector<string> grid;
    while (getline(inputStream, inputLine)) {
        grid.push_back(inputLine);        
    }
    
    int count = 0;
    for (int i = 1; i + 1 < grid.size(); i++) {
        for (int j = 1; j + 1 < grid[i].size(); j++) {
            string rightDownDiagonal = "";
            rightDownDiagonal.push_back(grid[i - 1][j - 1]);
            rightDownDiagonal.push_back(grid[i][j]);
            rightDownDiagonal.push_back(grid[i + 1][j + 1]);

            string leftDownDiagonal = "";
            leftDownDiagonal.push_back(grid[i - 1][j + 1]);
            leftDownDiagonal.push_back(grid[i][j]);
            leftDownDiagonal.push_back(grid[i + 1][j - 1]);

            if (isXMAS(rightDownDiagonal) && isXMAS(leftDownDiagonal)) {
                count++;
            }
        }
    }

    ofstream output("output/04_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << count;
}