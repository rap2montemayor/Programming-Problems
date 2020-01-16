#include <iostream>
using namespace std;

int check(int v, int k) {
    int count = v;
    int kexp = k;
    while (v/k > 0) {
        count += v/k;
        k *= kexp;
    }

    return count;
}

int main() {
    int n,k;
    cin >> n >> k;

    int lower = 1, upper = n;
    int mid; 
    while (lower < upper) {
        mid = (upper+lower) / 2;
        int a = check(mid, k);
        if (a >= n) {upper = mid;}
        else {lower = mid+1;}
    }
    
    cout << lower << endl;
    return 0;
}
