#include <bits/stdc++.h>
using namespace std;

vector<bool> once(1e9), twice(1e9);

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n, a, b;
    while (cin>>n>>a>>b) {
        int died = 0, x = 0;

        while (died < n) {
            x = (a * x * x + b) % n;
            if (!once[x]) once[x] = true;
            else if (!twice[x]) {
                twice[x] = true;
                died++;
            }
            else {
                break;
            }
        }

        cout << n - died << '\n';
    }

    return 0;
}