#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> subsetBitmask(vector<int> &arr, int bitmask) {
    set<int> subset;
    for (int i = 0; i < arr.size(); i++)
        if (bitmask & (1<<i)) subset.insert(arr[i]);
    return subset;
}


int getSetBits(int bitmask) {
    int setBits = 0;
    for (int i = 0; i < 30; i++)
        if (bitmask & (1<<i)) setBits++;
    return setBits;
}

set<set<int>> getSubsets(vector<int> &arr, int size) {
    set<set<int>> subsets;

    int bitmask = 0;
    while (bitmask < 1 << arr.size()) {
        if (getSetBits(bitmask) == size)
            subsets.insert(subsetBitmask(arr, bitmask));
        bitmask++;
    }

    return subsets;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        int n, k;

        cin >> n >> k;
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        set<set<int>> subsets = getSubsets(arr, k);
        for (set<int> s : subsets) {
            cout << "{";
            set<int>::iterator it = s.begin();
            while (it != s.end()) {
                cout << *it;
                it++;
                if (it != s.end()) cout << ",";
            }
            
            cout << "}" << endl;
        }
        if (subsets.empty())
            cout << "{}" << endl;
        cout << "---" << endl;
    }
    return 0;
}
