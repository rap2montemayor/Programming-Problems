#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> corners, potencies;

    while (cin >> n) {
        corners.resize(1 << n);
        potencies.resize(1 << n);
        for (int i = 0; i < 1 << n; i++)
            cin >> corners[i];

        for (int i = 0; i < corners.size(); i++)
            for (int j = 0; j < n; j++)
                potencies[i] += corners[i ^ 1 << j];

        int max = potencies[0] + potencies[1];
        for (int i = 0; i < potencies.size(); i++)
            for (int j = 0; j < n; j++)
                if (potencies[i] + potencies[i ^ 1 << j] > max)
                    max = potencies[i] + potencies[i ^ 1 << j];

        cout << max << endl;
        corners.clear();
        potencies.clear();
    }
    return 0;
}
