#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<vector<int>> edgelist;
    vector<vector<int>> adjlist;
    scanf("%d %d",&n,&m);
    adjlist.resize(n+1,vector<int>());

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        edgelist.push_back({n1, n2});
        adjlist[n1].push_back(n2);
        adjlist[n2].push_back(n1);
    }
   
    int min = ~(1<<31);
    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m; j++) {
            //check for common vertex
            for (int ii=0; ii<=1; ii++) {
                for (int jj=0; jj<=1; jj++) {
                    if (edgelist[i][ii] == edgelist[j][jj]) {
                        //check non common vertices for adjacency
                        for (int k : adjlist[edgelist[i][ii^1]]) {
                            if (k == edgelist[j][jj^1]) {
                                //count adjacent vertices
                                int count = adjlist[edgelist[i][ii]].size()
                                            + adjlist[edgelist[i][ii^1]].size()
                                            + adjlist[edgelist[j][jj^1]].size()
                                            - 6;
                                if (count < min) min = count;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (min == ~(1<<31)) printf("-1\n");
    else printf("%d\n",min);
    return 0;
}
