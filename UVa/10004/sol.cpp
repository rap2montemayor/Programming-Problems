#include <bits/stdc++.h>
using namespace std;

bool bicolorable(vector<vector<int>> &adjlist) {
    //modified bfs
    vector<int> colors(adjlist.size(),-1);
    queue<int> q;
    q.push(0);
    colors[0]=0;
    while (!q.empty()) {
        for (int i : adjlist[q.front()]) {
            if (colors[i]==-1) {
                colors[i]=colors[q.front()]^1;
                q.push(i);
            }
            if (colors[i]==colors[q.front()])
                return false;
        }
        q.pop();
    }

    return true;
}

int main() {
    int n,l;
    while (cin>>n>>l) {
        vector<vector<int>> adjlist(n);
        for (int i=0; i<l; i++) {
            int node,dest; cin>>node>>dest;
            adjlist[node].push_back(dest);
            adjlist[dest].push_back(node);
        }

        if (bicolorable(adjlist)) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
