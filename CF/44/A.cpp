#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<string> leaves;
    string s;

    cin >> n;
    getline(cin, s);

    while (n--) {
        getline(cin, s);
        leaves.insert(s);
    }

    cout << leaves.size() << endl;
    return 0;
}
