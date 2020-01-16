#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int evalBitmask(int bitmask, vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        if (bitmask & (1 << i))
            sum += arr[i];
    return sum;
}

int evalBitmaskRange(int bitmask, vector<int> &arr) {
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();
    for (int i = 0; i < arr.size(); i++) {
        if (bitmask & (1 << i)) {
            int current = arr[i];
            if (current < min) min = current;
            if (current > max) max = current;
        }
    }
    return max-min;
}

int subsetsum(vector<int> &arr, int min, int max, int range) {
    int ans = 0;
    int bitmask = 0;
    while (bitmask < 1 << arr.size()) {
        int result = evalBitmask(bitmask, arr);
        if (result >= min and result <= max) {
            int r = evalBitmaskRange(bitmask, arr);
            if (r >= range) ans++;
        }
        bitmask++;
    }

    return ans;
}

int main() {
    int n,l,r,x;
    vector<int> c;

    cin >> n >> l >> r >> x;
    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    cout << subsetsum(c, l, r, x) << endl;
    return 0;
}
