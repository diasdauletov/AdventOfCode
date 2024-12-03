#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int day = 1; day <= 25; day++) {
        string partOne = to_string(day / 10) + to_string(day % 10);
        string partTwo = partOne + "_2";

        ofstream output1(partOne + ".txt");
        output1 << endl;

        ofstream output2(partTwo + ".txt");
        output2 << endl;
    }
}