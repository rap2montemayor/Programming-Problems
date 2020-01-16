#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> maze;
vector<char> mapping;
string inputs;
int ans = 0;

bool test(vector<string> &maze, vector<char> &mapping) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            if (maze[i][j] == 'S') break; 
        if (maze[i][j] == 'S') break;
    }
    
    for (char c : inputs) {
        char in = mapping[c-'0'];
        switch (in) {
            case 'u':
                i--;
                break;
            case 'd':
                i++;
                break;
            case 'l':
                j--;
                break;
            case 'r':
                j++;
                break;
        }
        if (i < 0 or i >= n or
            j < 0 or j >= m or
            maze[i][j] == '#') break;
        if (maze[i][j] == 'E') return true;
    }

    return false;
}

void f(vector<char> &mapping, int size = 4) {
    if (size == 1) {
        if (test(maze, mapping))
            ans++;
    }
    else {
        f(mapping, size-1);
        for (int i = 0; i < size-1; i++) {
            if (size%2) {
                int temp = mapping[0];
                mapping[0] = mapping[size-1];
                mapping[size-1] = temp;
            }
            else {
                int temp = mapping[i];
                mapping[i] = mapping[size-1];
                mapping[size-1] = temp;
            }
            f(mapping, size-1);
        }
    }
}

int main() {
    cin >> n >> m;
    maze.reserve(n);
    mapping.reserve(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        maze.push_back(s);
    }
    cin >> inputs;

    mapping = {'u','d','l','r'};
    f(mapping);
    cout << ans << endl;
    return 0;
}
