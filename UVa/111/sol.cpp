#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> splitString(string s) {
    vector<int> v;
    string vs;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') { 
            v.push_back(stoi(vs));
            vs.clear();
        }
        else vs.push_back(s[i]);
        if (i == s.length()-1) v.push_back(stoi(vs));
    }

    return v;
}

vector<int> fix(vector<int> &v) {
    int size = v.size();
    vector<int> out(size);
    for (int i = 0; i < size; i++)
        out[v[i]-1] = i+1;
    
    return out;
}

int score(vector<int> &v1, vector<int> &v2) {
    int v1s = v1.size();
    int v2s = v2.size();
    vector<vector<int>> table(v1s, vector<int>(v2s, 0));

    for (int i = 0; i < v1s; i++) {
        for (int j = 0; j < v2s; j++) {
            if (i == 0) {
                if (v1[i] == v2[j]) table[i][j] = 1;
                else table[i][j] = table[i][j-1];
                continue;
            }
            if (j == 0) {
                if (v1[i] == v2[j]) table[i][j] = 1;
                else table[i][j] = table[i-1][j];
                continue;
            }
            if (v1[i] == v2[j]) {
                if (table[i-1][j] > table[i][j-1] + 1) table[i][j] = table[i-1][j];
                else table[i][j] = table[i][j-1]+1;
            }
            else {
                if (table[i-1][j] > table[i][j-1]) table[i][j] = table[i-1][j];
                else table[i][j] = table[i][j-1];
            }
        }
    }

    return table[v1s-1][v2s-1];
}

int main() {
    char cs[1000];
    vector<int> correct;
    int n;

    while (true) {
        cin.getline(cs, 1000);
        vector<int> v = splitString(cs);
        if (v.size() == 0) break;
        if (v.size() == 1) {
            n = v[0];
            cin.getline(cs, 1000);
            correct = splitString(cs);
            correct = fix(correct);
            continue;
        }

        v = fix(v);
        cout << score(v,correct) << endl;
    }
    return 0;
}
