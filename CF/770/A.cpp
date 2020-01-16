#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cout << char(97+i%k);
    cout << endl;
    return 0;
}
