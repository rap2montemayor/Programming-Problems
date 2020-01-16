#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long n, r;
    long long ans = 0;
    map<long long, long long> m;
    vector<long long> arr;

    cin >> n >> r;
    arr.reserve(n);

    while (n--) {
        long long x;
        cin >> x;
        arr.push_back(x);
        m[x]++;
    }
    
    for (long long i : arr) {
        long long x = 1;
        m[i]--;
        x *= m[i*r];
        m[i]--;
        x *= m[i*r*r];
        ans += x;
    }

    cout << ans << endl;
    return 0;
}
