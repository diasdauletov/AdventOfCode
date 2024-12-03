#include <bits/stdc++.h>
using namespace std;

// `levels` is safe if both of the following are true:
// * Any two adjacent levels differ by at least one and at most three.
// * The levels are either all increasing or all decreasing.
bool safe(const vector<int> & levels) {
    for (int i = 1; i < levels.size(); i++) {
        if (abs(levels[i] - levels[i - 1]) > 3 || levels[i] == levels[i - 1]) 
            return false;
    }
    // the diff sign should be always 1, if the levels increasing, and -1 if decreasing
    int diffSign = 0;
    for (int i = 1; i < levels.size(); i++) {
        bool increasing = levels[i] - levels[i - 1] > 0;

        if (diffSign == 1 && !increasing)
            return false;
        else if (diffSign == -1 && increasing)
            return false;

        diffSign = increasing ? 1 : -1;
    }
    return true;
}

int main() {
    ifstream inputStream("2_input.txt");
    
    // read the list of numbers in each line and determine if it is safe, and count the number of safe levels
    string inputLine;
    int res = 0;
    while (getline(inputStream, inputLine)) {
        vector<int> levels;
        istringstream sstream(inputLine);
        int level;
        while (sstream >> level) {
            levels.push_back(level);
        }
        res += safe(levels);
    }

    // result
    ofstream output("2_output.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}