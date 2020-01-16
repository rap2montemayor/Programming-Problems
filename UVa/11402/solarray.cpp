#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int n, *vals;
	char *deltas;

	segtree() {
		vals = new int[1024000*4];
		deltas = new char[1024000*4];
	}

	void init(vector<int> &ar) {
		n = ar.size();
		build(ar,1,0,n-1);
	}

	void build(vector<int> &ar, int p, int i, int j) {
		deltas[p] = 0;
		if (i==j) {
			vals[p]=ar[i];
			deltas[p]='X';
		}
		else {
			int k=(i+j)/2;
			build(ar,p<<1,i,k);
			build(ar,p<<1|1,k+1,j);
			pull(p);
		}
	}

	void pull(int p) {
		vals[p] = vals[p<<1] + vals[p<<1|1];
	}

	//visit
	void push(int p, int i, int j) {
		if (deltas[p]=='F') vals[p]=(j-i+1);
		else if (deltas[p]=='E') vals[p]=0;
		else if (deltas[p]=='I') vals[p]=(j-i+1)-vals[p];
		else return;

		if (i!=j) {
			char &l = deltas[p<<1], &r = deltas[p<<1|1];
			if (deltas[p]=='I') {
				if (l=='F') l='E';
				else if (l=='E') l='F';
				else if (l=='I') l='X';
				else l='I';
				
				if (r=='F') r='E';
				else if (r=='E') r='F';
				else if (r=='I') r='X';
				else r='I';
			}
			else {
				l = deltas[p];
				r = deltas[p];
			}
		}
		deltas[p]='X';
	}
	
	//modify
	void update(int _i, int _j, char op, int p, int i, int j) {
		push(p,i,j);
		if (_i <= i and j <= _j) {
			deltas[p] = op;
			push(p,i,j);
		}
		else if (_j < i or j < _i) {}
		else {
			int k = (i+j)/2;
			update(_i,_j,op,p<<1,i,k);
			update(_i,_j,op,p<<1|1,k+1,j);
			pull(p);
		}
	}

	int query(int _i, int _j, int p, int i, int j) {
		push(p,i,j);
		if (_i <= i and j <= _j) return vals[p];
		else if (_j < i or j < _i) return 0;
		else {
			int k=(i+j)/2;
			return query(_i, _j, p<<1, i, k) + query(_i,_j,p<<1|1, k+1,j);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin>>t;

	segtree st;
	for (int i=1; i<=t; i++) {
		cout << "Case " << i << ":\n";
		
		int m; cin>>m;
		vector<int> pirates;
		pirates.reserve(1024001);

		while (m--) {
			int mult; string s;
			cin>>mult>>s;
			while (mult--)
				for (char &c : s)
					pirates.push_back(c-'0');
		}
		st.init(pirates);

		int sz = pirates.size()-1;
		int q; cin>>q;
		int queryCount=1;
		while (q--) {
			char op; int l, r;
			cin>>op>>l>>r;
			if (op!='S') st.update(l,r,op,1,0,sz);
			else cout << "Q" << queryCount++ << ": " << st.query(l,r,1,0,sz) << '\n';
		}
	}
	return 0;
}
