#include <iostream>
using namespace std;

int m,n;
int total=0;
void gridPaths(int i, int j) {
    if (i==m and j==n) total++;

    if (i<m) gridPaths(i+1,j);
    if (j<n) gridPaths(i,j+1);
    if (i<m and j<n) gridPaths(i+1,j+1);
}

int main() {
    m=15;
    n=15;
    gridPaths(1,1);
    cout << total << endl;
    return 0;
}
