#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool superLucky(long long bitmask, int len) {
    int ones = 0;
    int zeroes = 0;
    
    for (int i = 0; i < len; i++) {
        if (bitmask & 1<<i) ones++;
        else zeroes++;
    }
    return ones == zeroes;
}

long long evalBitmask(long long bitmask, int len) {
    string s = "";
    for (int i = 0; i < len; i++) {
        if (bitmask & 1<<i) s.push_back('7');
        else s.push_back('4');
    }
    return stoll(s);
}

void superLuckyNumbers(int len, vector<long long> &nums, string current = "") {
    long long bitmask = 0;
    while (bitmask < 1<<len) {
        if (superLucky(bitmask, len))
            nums.push_back(evalBitmask(bitmask, len));
        bitmask++;
    }
}

int getDigits(long long n) {
    int len = 0;
    if (n == 0) return 1;
    while (n > 0) {
        n /= 10;
        len++;
    }

    return len;
}

long long bsearch(vector<long long> &arr, long long q) {
    int l = 0;
    int r = arr.size();
    int mid;
    while (l < r) {
        mid = (l+r) / 2;
        if (q < arr[mid])
            r = mid;
        else if (q > arr[mid])
            l = mid+1;
        else
            r = mid; 
    }

    return arr[l];
}

int main() {
    long long n;
    cin >> n;
    
    int len = getDigits(n);
    if (len % 2) len++;
    vector<long long> nums;
    superLuckyNumbers(len, nums);
    superLuckyNumbers(len+2, nums);
    sort(nums.begin(), nums.end());    
    cout << bsearch(nums, n) << endl;
}
