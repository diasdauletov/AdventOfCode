#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputStream("input/01_2.txt");

    vector<int> nums;
    map<int, int> count;
    int first, second;
    
    while (inputStream >> first >> second) {
        nums.push_back(first);
        count[second]++;
    }
    
    int res = 0;
    for (int num : nums) {
        res += count[num] * num;
    }

    ofstream output("output/01_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}