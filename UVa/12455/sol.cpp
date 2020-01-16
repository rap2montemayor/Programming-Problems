#include <iostream>
#include <vector>
using namespace std;

int evalBitmask(int bitmask, vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        if (bitmask & (1<<i)) sum += arr[i];
    return sum;
}

bool subsetSum(int target, vector<int> &arr) {
    int bitmask = 0;
    while (bitmask < 1<<arr.size()) {
        if (evalBitmask(bitmask, arr) == target) return true; 
        bitmask++;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        vector<int> arr;

        cin >> n >> p;
        arr.resize(p);
        for (int i = 0; i < p; i++)
            cin >> arr[i];
            
        if (subsetSum(n, arr)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
