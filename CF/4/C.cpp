#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    map<string, int> db;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        if (db[s]) {
            cout << s << db[s] << endl;
            db[s]++;
        }
        else {
            cout << "OK" << endl;
            db[s]++;
        }
    }
    return 0;
}
