#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    vector<int> army;
    
    cin >> n >> m >> k;
    army.reserve(m+1);
    
    for (int i = 0; i <= m; i++) {
        int x;
        cin >> x;
        army.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        army[i] = army[i] ^ army[m];
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int diff = 0, j = 0;
        
        while (1 << j <= army[i]) {
            if (army[i] & (1 << j)) diff++; 
            j++;
        }
        
        if (diff <= k) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
