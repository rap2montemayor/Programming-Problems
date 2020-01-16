#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k = 1;
    int b[16] = {1}; 
    while (k + k + 1 < 32) {
        b[k] = ((2 << k) - 1) * (2 << (k-1));
        k++;
    }

    for (int i = 15; i >= 0; i--) {
        if (n%b[i] == 0) {
            cout << b[i] << endl;
            break;
        }
    }

    return 0;
}
