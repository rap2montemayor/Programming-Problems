#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n; cin >> m >> n;

    vector<vector<int>> table(n,vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> table[j][i];

    vector<int> paintings(m, 0);
    for (int i = 0; i < n; i++) {
        int next = 0;
        for (int j = 0; j < m; j++) {
            if (paintings[j] > next) {
                paintings[j] += table[i][j];
            }
            else paintings[j] = next+table[i][j];
            next = paintings[j];
        }
    }

    for (int i : paintings) cout << i << endl;
    return 0;
}
