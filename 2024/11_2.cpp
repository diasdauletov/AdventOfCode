#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> update(long long num) {
    if (num == 0) return {1, -1};
    
    string numStr = to_string(num);
    if (int(numStr.size()) % 2 != 0) return {num * 2024ll, -1};

    string firstHalf = numStr.substr(0, numStr.size() / 2);
    string secondHalf = numStr.substr(numStr.size() / 2, numStr.size() / 2);
    return {stoull(firstHalf), stoull(secondHalf)};
}

map<pair<long long, int>, long long> memo;

long long blink(long long num, int cnt = 75) {
    if (cnt == 0) return 1;
    auto [num1, num2] = update(num);
    
    if (memo[{num1, cnt - 1}] == 0) {
        memo[{num1, cnt - 1}] = blink(num1, cnt - 1);
    }
    if (num2 != -1 && memo[{num2, cnt - 1}] == 0)
        memo[{num2, cnt - 1}] = blink(num2, cnt - 1);

    memo[{num, cnt}] = memo[{num1, cnt - 1}] + memo[{num2, cnt - 1}];
    return memo[{num, cnt}];
}

int main() {
    ifstream inputStream("input/11_2.txt");
    

    // parse input into the vector
    vector<long long> nums;
    string inputLine;
    getline(inputStream, inputLine);
    inputLine += ' ';
    long long num = 0;
    for (char ch : inputLine) {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + ch - '0';
        } else {
            nums.push_back(num);
            num = 0;
        }
    }

    long long res = 0;
    for (auto num : nums) {
        long long cnt = blink(num);
        res += cnt;
    }
    cout << res << endl;

    
    // Below it throws Segmenataution fault LOL
    // ofstream output("output/11.txt");
    // cout.rdbuf(output.rdbuf());
    // cout << res << endl;
}