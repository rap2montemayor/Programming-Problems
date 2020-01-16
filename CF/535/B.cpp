#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getDigits(int n) {
    int digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }
    return digits;
}

int in = 0;
int n;
void combination(int len, string result = "") {
    if (len == 0) {
        in++;
        int r;
        r = stoi(result);
        if (r == n) cout << in << endl;
        return;
    }
    else {
        result.push_back('4');
        combination(len-1, result);
        result.pop_back();

        result.push_back('7');
        combination(len-1, result);
        result.pop_back();
    }
}

int main() {
    int d, ans;
    cin >> n;
    d = getDigits(n);
    while (d-2 >= 0) {
        in += 2 << (d-2);
        d--;
    }
    combination(getDigits(n));
    return 0;
}
