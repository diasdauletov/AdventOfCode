#include <bits/stdc++.h>
using namespace std;

void dfs(string gate, map<string, vector<string>>& gateInputs, map<string, string>& gateType, map<string, int>& gateOutput) {
    if (gateOutput[gate] != -1)
        return;
    
    string op = gateType[gate];
    int initialValue = op == "AND" ? 1 : 0;
    for (auto input : gateInputs[gate]) {
        if (gateOutput[input] == -1)
            dfs(input, gateInputs, gateType, gateOutput);

        if (op == "AND") initialValue &= gateOutput[input];
        if (op == "XOR") initialValue ^= gateOutput[input];
        if (op == "OR") initialValue |= gateOutput[input];
    }

    gateOutput[gate] = initialValue;
}

int main() {
    ifstream inputStream("input/24_2.txt");

    map<string, string> gateType; // AND, XOR, OR, NULL
    map<string, int> gateOutput; // 1, 0, -1 (-1 means not computed)
    map<string, vector<string>> gateInputs; // gate can have other multiple gates as its input
    
    // Parse initial gate inputs, and they are assumed like a gate with type NULL for simplicity
    string inputLine;
    while (getline(inputStream, inputLine) && !inputLine.empty()) {
        // Parse this format "x00: 1"
        auto gateName = inputLine.substr(0, 3);
        gateType[gateName] = "NULL";
        gateOutput[gateName] = (inputLine.substr(5, 1) == "1") ? 1 : 0;
        gateInputs[gateName] = {};
    }

    while (getline(inputStream, inputLine) && !inputLine.empty()) {
        // Parse this format "x00 AND y00 -> z00"
        string type = inputLine.substr(4, inputLine[4] == 'O' ? 2 : 3);
        // Erase the gate type for simplicity => "x00  y00 -> z00"
        inputLine.erase(4, type.size());

        auto gateX = inputLine.substr(0, 3);
        auto gateY = inputLine.substr(5, 3);
        auto gateZ = inputLine.substr(12, 3);

        gateType[gateZ] = type;
        gateOutput[gateZ] = -1;
        gateInputs[gateZ].push_back(gateX);
        gateInputs[gateZ].push_back(gateY);
    }

    for (auto [gateName, output] : gateOutput) {
        dfs(gateName, gateInputs, gateType, gateOutput);
    }

    vector<string> orderedGates;
    for (auto it : gateType) {
        if (it.first[0] != 'z') continue;
        orderedGates.push_back(it.first);
    }
    sort(orderedGates.begin(), orderedGates.end());

    long long result = 0;
    for (int i = 0; i < orderedGates.size(); i++) {
        result += ((1ll << i) * gateOutput[orderedGates[i]]);
    }
    cout << result;
}