#include <bits/stdc++.h>
using namespace std;

int solve(string str) {
    int res = 0;

    for (int i = 0; i + 3 < str.size(); i++) {
        // check that str[i..<i+3] = "mul"
        if (str.substr(i, 3) != "mul") continue;
        
        // check that after "mul" there is "("
        if (i + 3 >= str.size() || str[i + 3] != '(') continue;
        
        // parse the first number in "mul(first,second)"
        i += 4;
        int first = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            first = first * 10 + str[i++] - '0';
        }

        // check that after "mul(first" there is ","
        if (i >= str.size() || str[i] != ',') continue;

        // parse the second number in "mul(first, second)"
        i += 1;
        int second = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            second = second * 10 + str[i++] - '0';
        }
        
        // check that after "mul(first, second" there is ")"
        if (i >= str.size() || str[i] != ')') continue;

        res += first * second;
    }

    return res;
}

int main() {
    ifstream inputStream("input/03.txt");
    
    string inputLine;
    int res = 0;
    while (getline(inputStream, inputLine)) {
        istringstream sstream(inputLine);
        res += solve(inputLine);
    }

    ofstream output("output/03.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}