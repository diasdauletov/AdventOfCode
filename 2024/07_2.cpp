#include <bits/stdc++.h>
using namespace std;

bool find(long long total, vector<long long> & nums, int pos = 0, long long cur = 0) {
    if (pos >= nums.size())
        return cur == total;
    
    if (cur + nums[pos] <= total && find(total, nums, pos + 1, cur + nums[pos]))
        return true;
    
    if (pos > 0) { 
        string concat = to_string(cur) + to_string(nums[pos]);
        string totalStr = to_string(total);
        if (concat.size() <= totalStr.size() && stoll(concat) <= total && find(total, nums, pos + 1, stoll(concat))) {
            return true;
        }
    }

    if (pos == 0) cur = 1;
    return cur * nums[pos] <= total && find(total, nums, pos + 1, cur * nums[pos]);
}

int main() {
    ifstream inputStream("input/07_2.txt");

    long long res = 0;    
    string inputLine;
    while (getline(inputStream, inputLine)) {
        // parse the input
        vector<long long> nums;
        long long total = stoll(inputLine.substr(0, inputLine.find(':')));
        long long num = 0;
        inputLine += '.';
        for (int i = inputLine.find(':') + 1; i < inputLine.size(); i++) {
            if (inputLine[i] >= '0' && inputLine[i] <= '9') {
                num = num * 10 + inputLine[i] - '0';
            } else if (num != 0) {
                nums.push_back(num);
                num = 0;
            }
        }

        if (find(total, nums)) {
            res += total;
        }
    }

    ofstream output("output/07_2.txt");
    cout.rdbuf(output.rdbuf());
    cout << res << endl;
}