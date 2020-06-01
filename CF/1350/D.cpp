#include <bits/stdc++.h>

using namespace std;

vector<bool> isdiv(1e9+1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n, k; cin>>n>>k;
        fill(isdiv.begin(), isdiv.begin()+n, false);

        vector<int> divs;
        for (int i = 2; i <= min(n,k); i++) {
            if (n%i == 0) {
                int div = i;

                while (n % div == 0) {
                    isdiv[div] = true;
                    divs.push_back(div);
                    if (div > min(n,k)) break;

                    for (int x : divs) {
                        if (div*x > min(n,k)) continue;
                        if (n % (div * x) == 0) {
                            isdiv[div*x] = true;
                            divs.push_back(div*x);
                        }
                    }

                    div *= i;
                }
            }
        }

        for (int i : divs) cout << i << ' ';
        cout << endl;
    }
    return 0;
}