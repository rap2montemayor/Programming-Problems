#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, x;
    map<int, int> count;
    vector<int> arr;

    cin >> n >> x;
    arr.reserve(n);

    while (n--) {
        int y;
        cin >> y;
        arr.push_back(y);
        count[y]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]--;
        int j = x ^ arr[i];
        ans += count[j];
    }

    cout << ans << endl;
    return 0;
}
