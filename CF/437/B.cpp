#include <iostream>
#include <set>
using namespace std;

int lowbit(int n) {
    int bit = 0;
    while (1 << bit <= n) {
        if (n & (1 << bit)) break;
        bit++;
    }

    return 1 << bit;
}

int main() {
    int sum, limit;
    set<int> ans;
    cin >> sum >> limit;

    int pow = 0;
    while (1 << (pow+1) <= limit) pow++;
    while (sum > 0 and pow >= 0) {
        int add = 1 << pow;
        while (lowbit(add) <= sum and add <= limit) {
            sum -= lowbit(add);
            ans.insert(add);
            add += 1 << (pow+1);
        }
        pow--;
    }

    if (sum) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
