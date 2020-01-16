#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    set<string> names;
    vector<string> messages;
    
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        messages.push_back(s);
    }

    for (int i = messages.size()-1; i >= 0; i--) {
        if (!names.count(messages[i])) {
            cout << messages[i] << endl;
            names.insert(messages[i]);
        }
    }

    return 0;
}
