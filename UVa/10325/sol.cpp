#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long gcd(long long a, long long b) {
    return b==0 ? a : gcd(b,a%b);
}

vector<long long> nums;
long long count(long long idx = 0, long long div = 1, long long elems=0) {
    if (idx >= nums.size()) {
        if (elems%2==0) return n/div;
        else return -n/div;
    }

    long long ans=0;
    ans += count(idx+1, div*nums[idx]/gcd(div,nums[idx]), elems+1);
    ans += count(idx+1, div, elems);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (cin>>n>>m) {
        nums.resize(m);
        for (long long i=0; i<m; i++)
            cin>>nums[i];
        cout << count() << endl;
    }
    return 0;
}