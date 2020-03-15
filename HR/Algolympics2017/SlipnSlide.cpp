#include <bits/stdc++.h>
using namespace std;

struct bitTree {
	ll tree=(1LL<<32)-1;
	ll nodes;

	bitTree(ll n) { nodes=n; }
	ll get(ll node) { return (tree>>(node*4))&0b1111; }
	void set(ll node, ll val) {
	}
};

bool hasCycle(vector<ll> &tree, ll v, ll current) {
	while (v>=0 and v!=tree[v]) {
		if (tree[v]==current) return true;
		v=tree[v];
	} 
	return false;
}

void treeGen(ll root, ll current, vector<ll> &tree, vector<vector<ll>> &trees) {
	bool done=true;
	for (ll i : tree) if (i==-1) done=false;
	if (done) {
		trees.push_back(tree);	
		return;
	}

	for (ll i=0; i<tree.size(); i++) {
		if (i==current or hasCycle(tree,i,current)) continue;
		tree[current]=i;
		treeGen(root,current+1,tree,trees);
		tree[current]=-1;
	}
}

vector<bitTree> treesOfSize[9]; 
int main() {
	bitTree tree(8);
	for (int i=0; i<8; i++)
		cout << tree.get(i) << ' ';
	cout << endl;
	tree.set(0,1);
	tree.set(1,1);
	tree.set(2,1);
	tree.set(3,1);
	tree.set(4,1);
	tree.set(5,1);
	tree.set(6,1);
	tree.set(7,1);
	for (int i=0; i<8; i++)
		cout << tree.get(i) << ' ';
	cout << endl;

	/*
	//pregenerate trees
	for (ll i=2; i<=8; i++) {
		bitTree tree(i);
		tree.set(0,0);
		treeGen(0,1,tree,treesOfSize[i]);
	}

	ll t; cin>>t;
	while (t--) {
		ll n; cin>>n;
		vector<char> d(n);
		vector<ll> r(n);
		for (ll i=0; i<n; i++)
			cin>>d[i]>>r[i];
		
		ll ans=-1;
		for (vector<ll> &g : treesOfSize[n]) {
			ll boring=0;
			ll variety=0;
			for (ll u=1; u<g.size(); u++) {
				ll v = g[u];
				if (d[u]==d[v]) boring+=r[u]*r[v];
				else variety+=r[u]*r[v];
			}
			if (ans==-1) ans=abs(boring-variety);
			else ans = min(ans,abs(boring-variety));
		}
		cout << ans << endl;
	}
	*/
	return 0;
}
