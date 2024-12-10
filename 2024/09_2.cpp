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
    ifstream inputStream("input/09_2.txt");
    
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

    vector<set<int>> freeSpaces(10, set<int>());
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] != -1) continue;
        
        int j = i;
        while (j + 1 < disk.size() && disk[j + 1] == -1) j++;

        freeSpaces[j - i + 1].insert(i);
        i = j;
    }

    for (int i = disk.size() - 1; i >= 0; i--) {
        if (disk[i] == -1) continue;
        
        int j = i;
        while (j - 1 >= 0 && disk[j - 1] == disk[i]) j--;
        int fileSpace = i - j + 1;

        int leftMostIndex = INT_MAX;
        int usedSpace = -1;
        // Find the leftmost span of free space blocks that could fit the file
        for (int space = fileSpace; space <= 9; space++) {
            if (!freeSpaces[space].empty() && *freeSpaces[space].begin() < leftMostIndex) {
                leftMostIndex = *freeSpaces[space].begin();
                usedSpace = space;
            }
        }

        if (leftMostIndex < j) {
            // move the file
            while (i >= j) swap(disk[leftMostIndex++], disk[i--]);
            
            // remove the used space 
            freeSpaces[usedSpace].erase(*freeSpaces[usedSpace].begin());
            // add a new free space that might left
            int remaingingSpace = usedSpace - fileSpace;
            int remaingingSpaceStartIndex = leftMostIndex;
            freeSpaces[remaingingSpace].insert(remaingingSpaceStartIndex);
        }
        i = j;
    }

    long long res = 0;
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] == -1) continue;
        res += disk[i] * i;
    }

    ofstream output("output/09_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}