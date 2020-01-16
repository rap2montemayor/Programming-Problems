#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> xsegs, ysegs;
    int n;
    cin >> n;

    while (n > 0) {
        int x, y;
        cin >> x >> y;
        xsegs.insert(x);
        ysegs.insert(y);
        n--;
    }
    
    if (xsegs.size() <= ysegs.size()) cout << xsegs.size() << endl;
    else cout << ysegs.size() << endl;
}
