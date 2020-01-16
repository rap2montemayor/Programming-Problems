#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<pair<int, int>> stack;
    vector<pair<int, int>> validseq;
    vector<pair<int, int>> valid;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' or '[') {
            pair<int, int> x = {0, -1};
            stack.push_back(x);
        }
        else if (s[i] == ')') {
            if (s[stack.back().first] == '(') {
                stack.back().second = i;
                validseq.push_back(stack.back());
                stack.pop_back();
            }
            else {
                if (!validseq.empty()) {
                    valid.push_back(validseq.back());
                }
            }
        }
        else if (s[i] == ']') {
            if (s[stack.back().first] == '[') {
                stack.back().second = i;
                validseq.push_back(stack.back());
                stack.pop_back();
            }
            else {
                if (!validseq.empty()) {
                    valid.push_back(validseq.back());
                }
            }
        }

        if (i == s.length()-1) {
            if (!validseq.empty()) {
                valid.push_back(validseq.back());
            }
        }
    }

    cout << s << endl;
    for (pair<int, int> i : valid) {
        cout << "start: " << i.first << ", end: " << i.second << endl;
    }

    return 0;
}
