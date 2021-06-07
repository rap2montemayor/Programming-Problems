#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int h, w;
char g[2001][2001];

int start[2001][2001], you[2001][2001], opp[2001][2001];

//im so sorry
void ans() {
    bool right = 1 != w, down = 1 != h;
    int choice2 = you[1][0] - opp[1][0],
        choice1 = you[0][1] - opp[0][1];

    if (not right and not down)
        cout << "Draw\n";
    else if (right and not down) {
        if (choice1 > 0) cout << "Takahashi\n";
        else if (choice1 < 0) cout << "Aoki\n";
        else cout << "Draw\n";
    }
    else if (not right and down) {
        if (choice2 > 0) cout << "Takahashi\n";
        else if (choice2 < 0) cout << "Aoki\n";
        else cout << "Draw\n";
    }
    else {
        if (choice1 > choice2) {
            if (choice1 > 0) cout << "Takahashi\n";
            else if (choice1 < 0) cout << "Aoki\n";
            else cout << "Draw\n";
        }
        else {
            if (choice2 > 0) cout << "Takahashi\n";
            else if (choice2 < 0) cout << "Aoki\n";
            else cout << "Draw\n";
        }
    }
}

void process() {
    memset(you, -1, sizeof(you));
    memset(opp, -1, sizeof(opp));
    you[h-1][w-1] = g[h-1][w-1] == '+' ? 1 : -1;
    opp[h-1][w-1] = you[h][w] = opp[h][w] = 0;

    for (int i = h-2, j = w-1; i >= 0; --i) {
        int x = g[i][j] == '+' ? 1 : -1;
        x += opp[i+1][j];
        you[i][j] = x;
        opp[i][j] = you[i+1][j];
    }
    for (int i = h-1, j = w-2; j >= 0; --j) {
        int x = g[i][j] == '+' ? 1 : -1;
        x += opp[i][j+1];
        you[i][j] = x;
        opp[i][j] = you[i][j+1];
    }

    for (int i = h-2; i >= 0; --i) {
        for (int j = w-2; j >= 0; --j) {
            int x = g[i][j] == '+' ? 1 : -1,
                choice1 = you[i+1][j] - opp[i+1][j],
                choice2 = you[i][j+1] - opp[i][j+1];

            if (choice1 > choice2) {
                x += opp[i+1][j];
                you[i][j] = x;
                opp[i][j] = you[i+1][j];
            }
            else {
                x += opp[i][j+1];
                you[i][j] = x;
                opp[i][j] = you[i][j+1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(g, 'x', sizeof(g));
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> g[i][j];

    process();
    ans();

    return 0;
}