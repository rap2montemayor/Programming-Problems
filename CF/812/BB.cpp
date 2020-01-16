#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

bool allZeroes(string s) {
    for (char c : s)
        if (c == '1') return false;
    return true;
}

int leftOn(string &s) {
    for (int i = 1; i < s.length(); i++)
        if (s[i] == '1') return s.length()-1-i;
    return 0;
}

int rightOn(string &s) {
    for (int i = s.length()-1; i >= 0; i--)
        if (s[i] == '1') return i;
    return 0;
}

int evalBitmask(int bitmask, vector<string> &building) {
    int result = 0;
    for (int i = 0; i < building.size(); i++) {
        if (bitmask & 1<<i) {
            int l = leftOn(building[i]);
            result += l;
            if (i < building.size()-1) {
                if (bitmask & 1<<(i+1))
                    result += l; 
                else
                    result += building[0].length()-1-l;
            }
        }
        else {
            int r = rightOn(building[i]);
            result += r;
            if (i < building.size()-1) {
                if (bitmask & 1<<(i+1))
                    result += building[0].length()-1-r;
                else
                    result += r;
            }
        }
        if (i < building.size()-1) result++;
    }

    return result;
}

int lightsOff(vector<string> &building) {
    int bitmask = 0;
    int min = numeric_limits<int>::max();
    while (bitmask < 1<<building.size()) {
        int current = evalBitmask(bitmask, building);
        if (current < min) min = current;
        bitmask += 2;
    }

    return min;
}

int main() {
    int n, m;
    vector<string> building;

    cin >> n >> m;
    building.resize(n);
    for (int i = n-1; i >= 0; i--)
        cin >> building[i];
    while (allZeroes(building.back())) {
        building.pop_back();
        if (building.empty()) break;
    }

    cout << lightsOff(building) << endl;
    return 0;
}
