#include <iostream>
using namespace std;

int main() {
    long long k;
    cin >> k >> k;

    long long i = 0;
    long long ans = 0;
    while (1 << i < k) {
        if (k & ((long long)1 << i) ) break;
        i++;
    }

    cout << i+1 << endl;
    return 0;
}
