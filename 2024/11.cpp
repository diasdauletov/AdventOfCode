#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> update(long long num) {
    if (num == 0) return {1, -1};
    
    string numStr = to_string(num);
    if (int(numStr.size()) % 2 != 0) return {num * 2024ll, -1};

    string firstHalf = numStr.substr(0, numStr.size() / 2);
    string secondHalf = numStr.substr(numStr.size() / 2, numStr.size() / 2);
    return {stoll(firstHalf), stoll(secondHalf)};
}

vector<long long> blink(vector<long long> nums) {
    vector<long long> res;
    for (long long num : nums) {
        auto [updated, possiblyNew] = update(num);
        res.push_back(updated);
        if (possiblyNew != -1)
            res.push_back(possiblyNew);
    }
    return res;
}

int main() {
    ifstream inputStream("input/11.txt");
    

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

    int blinks = 25;
    while (blinks-- > 0) {
        nums = blink(nums);
    }


    ofstream output("output/11.txt");
    cout.rdbuf(output.rdbuf());
    cout << nums.size() << endl;
}