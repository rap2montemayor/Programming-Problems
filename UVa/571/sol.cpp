#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <string>
using namespace std;

set<pair<int, int>> states;
vector<string> output;

void fillA(pair<int, int> &current, pair<int, int> &max) {
    current.first = max.first;
}

void fillB(pair<int, int> &current, pair<int, int> &max) {
    current.second = max.second;
}

void emptyA(pair<int, int> &current) {
    current.first = 0;
}

void emptyB(pair<int, int> &current) {
    current.second = 0;
}

void pourAB(pair<int, int> &current, pair<int, int> &max) {
    current.second += current.first;
    current.first = 0;

    if (current.second > max.second) {
        current.first = current.second-max.second;
        current.second = max.second;
    }
}

void pourBA(pair<int, int> &current, pair<int, int> &max) {
    current.first += current.second;
    current.second = 0;

    if (current.first > max.first) {
        current.second = current.first-current.first;
        current.first = max.first;
    }
}

void reset(pair<int, int> &current, pair<int, int> &orig) {
    current.first = orig.first;
    current.second = orig.second;
}

void jugs(int &n, pair<int, int> &max, pair<int, int> &current) {
    states.insert(current);
    if (current.first == n or current.second == n) {
        for (string s : output)
            cout << s << endl;
        cout << "success" << endl;
        return;
    }
    pair<int, int> orig(current);

    //fill a
    fillA(current, max);
    if (!states.count(current)) {
        output.push_back("fill A");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);

    //fill b
    fillB(current, max);
    if (!states.count(current)) {
        output.push_back("fill B");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);

    //empty a
    emptyA(current);
    if (!states.count(current)) {
        output.push_back("empty A");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);

    //empty b
    emptyB(current);
    if (!states.count(current)) {
        output.push_back("empty B");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);

    //pour a b
    pourAB(current, max);
    if (!states.count(current)) {
        output.push_back("pour A B");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);

    //pour b a
    pourBA(current, max);
    if (!states.count(current)) {
        output.push_back("pour B A");
        jugs(n, max, current);
        output.pop_back();
        if (current.first == n or current.second == n) return;
    }
    reset(current, orig);
}

int main() {
    pair<int, int> max;
    pair<int, int> current = {0,0};
    int n;

    while (cin >> max.first >> max.second >> n) {
        current = {0,0};
        states.clear();
        output.clear();

        jugs(n, max, current);
    }
    return 0;
}
