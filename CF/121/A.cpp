#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

set<long long> luckynumbers;

long long evalBitmask(int length, int bitmask) {
    string out = "";
    for (int i = length-1; i >= 0; i--) {
        if (bitmask & (1<<i)) out.push_back('7');
        else out.push_back('4');
    }

    return stoll(out);
}

void luckyGen() {
    //max length 10
    int bitmask = 0;
    while (bitmask < 1<<11) {
        for (int i = 1; i <= 10; i++)
            luckynumbers.insert(evalBitmask(i, bitmask));
        bitmask++;
    }
}

long long next(long long n) {
    return *lower_bound(luckynumbers.begin(), luckynumbers.end(), n);
}

int main() {
    long long l, r;
    long long sum = 0;
    cin >> l >> r;
    luckyGen();

    long long n = l;
    while (n <= r) {
        sum += next(n) * (next(n)-n+1);
        n = next(n)+1;
    }
    
    if (next(r) != r)
        sum -= next(r) * (next(r)-r);

    cout << sum << endl;
    return 0;
}
