#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;

    cin >> n;

    int i = 0;
    while (1 << i <= n) {
        if (n & (1 << i))
            ans++;
        i++;
    }

    cout << ans << endl;
    return 0;
}
