#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int> &arr) {
    int current = arr[0];
    int max = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (current + arr[i] > arr[i]) current += arr[i];
        else current = arr[i];

        if (current > max) max = current;
    }

    return max;
}

int maxSubsequence(vector<int> &arr) {
    int sum = 0;
    int zerocount = 0;
    int max = arr[0];

    for (int i : arr) {
        if (i > 0) sum += i;
        if (i == 0) zerocount++;
        if (i > max) max = i;
    }

    if (sum == 0) {
        if (zerocount == 0)
            return max;
        else return sum;
    }
    else return sum;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << maxSubarray(arr) << " " << maxSubsequence(arr) << endl;
    }

    return 0;
}
