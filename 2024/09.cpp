#include <bits/stdc++.h>
using namespace std;

void print(vector<int> disk) {
    for (auto x : disk) {
        if (x == -1) cout << '.';
        else cout << x;
    }
    cout << endl;
}

int main() {
    ifstream inputStream("input/09.txt");
    
    string inputLine;
    getline(inputStream, inputLine);

    // parse input
    vector<int> disk;
    for (int i = 0; i < inputLine.size(); i += 2) {
        int size = inputLine[i] - '0';
        int space = inputLine[i + 1] - '0';
        while (size-- > 0) disk.push_back(i / 2);
        while (space-- > 0) disk.push_back(-1);
    }

    for (int i = disk.size() - 1, freePos = 0; i > freePos; i--) {
        if (disk[i] == -1) continue;

        while (freePos < i && disk[freePos] != -1) freePos++;

        swap(disk[freePos], disk[i]);
    }

    long long res = 0;
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] == -1) break;
        res += disk[i] * i;
    }

    ofstream output("output/09.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}