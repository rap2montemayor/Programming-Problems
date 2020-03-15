#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool hasCycle(vector<int> &tree, int v, int current) {
	while (v>=0 and v!=tree[v]) {
		if (tree[v]==current) return true;
		v=tree[v];
	} 
	return false;
}

void treeGen(int root, int current, vector<int> &tree, vector<vector<int>> &trees) {
	bool done=true;
	for (int i : tree) if (i==-1) done=false;
	if (done) {
		trees.push_back(tree);	
		return;
	}

	for (int i=0; i<tree.size(); i++) {
		if (i==current or hasCycle(tree,i,current)) continue;
		tree[current]=i;
		treeGen(root,current+1,tree,trees);
		tree[current]=-1;
	}
}

vector<vector<int>> treesOfSize[9]; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	for (int i=2; i<=8; i++) {
		vector<int> tree(i,-1);
		tree[0]=0;
		treeGen(0,1,tree,treesOfSize[i]);
	}

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vector<char> d(n);
		vector<ll> r(n);
		for (int i=0; i<n; i++)
			cin>>d[i]>>r[i];
		
		ll ans=-1;
		for (vector<int> &g : treesOfSize[n]) {
            ll temp=0;
			for (int u=1; u<g.size(); u++) {
				int v = g[u];
				if (d[u]==d[v]) temp+=r[u]*r[v];
				else temp-=r[u]*r[v];
			}
			if (ans==-1) ans=abs(temp);
			else ans = min(ans,abs(temp));
		}
		cout << ans << endl;
	}
	return 0;
}
