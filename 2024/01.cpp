#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputStream("input/01.txt");

    // read input and save the first and the second list
    vector<int> first, second;
    pair<int, int> pair;
    while (inputStream >> pair.first >> pair.second) {
        first.push_back(pair.first);
        second.push_back(pair.second);
    }
    // sort them and comput the distance sum
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int sum = 0;
    for (int i = 0; i < first.size(); i++) {
        sum += abs(first[i] - second[i]);
    }

    // result
    ofstream output("output/01.txt");
    cout.rdbuf(output.rdbuf());
    cout << sum;
}