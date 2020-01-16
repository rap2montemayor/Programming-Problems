#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int evalBitmask(vector<int> &arr, int bitmask) {
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
        if (bitmask & (1 << i)) result += arr[i];

    return result;
}

bool uniqueSubset(vector<int> &arr, vector<int> &bitmasks, int bitmask) {
    multiset<int> s;
    for (int i = 0; i < arr.size(); i++)
        if (bitmask & 1<<i) s.insert(arr[i]);
    
    for (int bm : bitmasks) {
        multiset<int> comp;
        for (int i = 0; i < arr.size(); i++)
            if (bm & 1<<i) comp.insert(arr[i]);

        if (s == comp) return false;
    }

    return true;
}

vector<int> subsetSum(vector<int> &arr, int goal) {
    vector<int> bitmasks;
    int bitmaskreturn = 0;
    int bitmask = 0;

    while (bitmask < 1 << arr.size()) {
        int result = evalBitmask(arr, bitmask);
        if (result == goal)
            if (uniqueSubset(arr, bitmasks, bitmask))
                bitmasks.push_back(bitmask);
        bitmask++;
    }

    return bitmasks;
}

vector<vector<int>> bitmasksToVector(vector<int> &arr, vector<int> bitmasks) {
    vector<vector<int>> sums;

    for (int bitmask : bitmasks) {
        vector<int> v;
        for (int i = 0; i < arr.size(); i++)
            if (bitmask & 1<<i) v.push_back(arr[i]);
        
        sort(v.begin(), v.end(), [](int a, int b){return a > b;});
        sums.push_back(v);
    }

    sort(sums.begin(), sums.end());
    reverse(sums.begin(), sums.end());
    return sums;
}

int main() {
    int t, n;
    vector<int> arr;
    while (cin >> t >> n) {
        if (t == 0 and n == 0) break;
        
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> bitmasks = subsetSum(arr, t);
        vector<vector<int>> sums = bitmasksToVector(arr, bitmasks);
        
        cout << "Sums of " << t << ":" << endl;
        if (sums.empty()) {
            cout << "NONE" << endl;
            continue;
        }
        for (vector<int> v : sums) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i < v.size()-1) cout << "+";
            }
            cout << endl;
        }
    }
}
