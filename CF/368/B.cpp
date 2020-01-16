#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    vector<int> arr;
    vector<int> uniques;
    set<int> s;
    
    cin >> n >> m;
    arr.reserve(n); 
    uniques.resize(n,0);

    while (n--) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int u = 0;
    for (int i = arr.size()-1; i >= 0; i--) {
        if (!s.count(arr[i])) {
            u++;
            s.insert(arr[i]);
        }
        uniques[i] = u;
    }

    while (m--) {
        int q;
        cin >> q;
        cout << uniques[q-1] << endl;
    }

    return 0;
}   
