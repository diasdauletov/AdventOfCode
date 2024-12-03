// Notes: 
// * mul(X,Y), where X and Y are each 1-3 digit numbers. For instance, mul(44,46) multiplies 44 by 46 to get a result of 2024. Similarly, mul(123,4) would multiply 123 by 4.

#include <bits/stdc++.h>
using namespace std;
int sumOfMultiplies(string str) {
    // the min "mul(X,Y)" length is 8
    const int MIN_MUL_LENGTH = 8;
    
    for (int i = 0; i < str.size(); i++) {
        if (i + MIN_MUL_LENGTH > str.size()) break;
        if (str.substr(i + 4) != "mul(") continue;
    }
}

int main() {
    ifstream inputStream("3_input.txt");
    
    string inputLine;
    int res = 0;
    while (getline(inputStream, inputLine)) {
        res += sumOfMultiplies(inputLine);
    }

    // result
    ofstream output("3_output.txt");
    cout.rdbuf(output.rdbuf());
    cout << res;
}