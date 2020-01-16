#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> memo;
string s1;
string s2;

void lcs(int l1, int l2) {
    //l1 and l2 are indices of s1 and s2
    //the cell memo[l1+1][l2+1] are what will be updated
    if (s1[l1] == s2[l2])
        memo[l1+1][l2+1] = 1+memo[l1][l2];
    else {
        if (memo[l1+1][l2] > memo[l1][l2+1]) memo[l1+1][l2+1] = memo[l1+1][l2];
        else memo[l1+1][l2+1] = memo[l1][l2+1];
    }
}

int main() {
    char c1[1000];
    char c2[1000];
    cin.getline(c1, 1000);
    cin.getline(c2, 1000);
    while (cin) {
        s1 = c1;
        s2 = c2;
        memo.clear();
        for (int i = 0; i <= s1.length(); i++) {
            vector<int> v (s2.length()+1, 0);
            memo.push_back(v);
        }

        for (int i = 0; i < s1.length(); i++)
            for (int j = 0; j < s2.length(); j++)
                lcs(i,j);
        
        cout << memo[s1.length()][s2.length()] << endl;
        cin.getline(c1, 1000);
        cin.getline(c2, 1000);
    }
    return 0;
}
