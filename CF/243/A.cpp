#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    //2^20
    int n;
    vector<int> arr;
    vector<int> arr2;
    set<int> res;

    cin >> n;
    arr.reserve(n);
    arr2.reserve(n);
    while (n--) {
        int x;
        cin >> x;
        arr.push_back(x);
        res.insert(x);
    }
   
    while (arr.size()) {
        for (int i = 0; i < arr.size()-1; i++) {
            int x = (arr[i] | arr[i+1]);
            if (!arr2.empty() and arr2.back() == x) continue;
            arr2.push_back(x);
            res.insert(x);
        }
        arr = vector<int>(arr2);
        arr2.clear();
    }

    cout << res.size() << endl;
}
