#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int maxdepth = 1;
void group(vector<vector<int>> &tree, int vertex, int depth=1) {
    if (visited[vertex]) return;
    visited[vertex]=true;
    if (maxdepth<depth)maxdepth=depth;
    visited[vertex] = true;
    
    for (int i : tree[vertex])
        group(tree, i, depth+1);
}

int main() {
    int n; scanf("%d",&n);
    vector<vector<int>> tree(n+1);
    vector<int> roots;
    visited.resize(n+1);

    for (int i=1; i<=n; i++) {
        int a; scanf("%d",&a);
        if (a==-1) roots.push_back(i);
        else tree[a].push_back(i);
    }

    for (int i : roots)
        group(tree,i);

    printf("%d\n",maxdepth);
    return 0;
}
