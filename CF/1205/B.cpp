#include <bits/stdc++.h>
using namespace std;
#define ll long long

int shortestCycle(ll source, vector<vector<ll>> &graph) {
    vector<bool> visited(graph.size());
    queue<ll> bfsqueue;
    bfsqueue.push_back(source);
    ll length=1;
    while (!bfsqueue.empty()) {
        visited[bfsqueue.front()]=true;
        for (int i=0; i<graph.size(); i++) {
            if (i==source) continue;
            if (!graph[source][i]) bfsqueue.push_back(i);
        }
        bfsqueue.pop_back();
    }
}

int main() {
    ll n; cin>>n;
    vector<ll> nums(n); 
    vector<vector<ll>> graph(n,vector<ll>(n,0));
    
    for (ll i=0; i<n; i++)
        cin>>nums[i];
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<n; j++) {
            if (i==j) continue;
            if ( (nums[i]&nums[j]) != 0) {
                graph[i][j]=1;
                graph[j][i]=1;
            }
        }
    }
    return 0;
}
