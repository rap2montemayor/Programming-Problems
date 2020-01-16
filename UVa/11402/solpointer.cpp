#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int i, j, val;
	char op;
	segtree *l=NULL, *r=NULL;

	void init(vector<int> &ar, int _i, int _j) {
		i = (_i); j = (_j);
		op='X';

		if (i==j) {
			val = ar[i];
			if (l) {
				l->val=-1;
				r->val=-1;
			}
		}
		else {
			int k = (i+j) >> 1;
			if (!l) {
				l = new segtree();
				r = new segtree();
			}
			l->init(ar,i,k);
			r->init(ar,k+1,j);

			val = max(0,l->val) + max(0,r->val);
		}
	}

	void visit() {
		if (op=='F') val = (j-i+1);
		else if (op=='E') val = 0;
		else if (op=='I') val = (j-i+1)-val;
		else return;

		if (l and l->val!=-1) {
			if (op=='I') {
				if (l->op=='F') l->op='E';
				else if (l->op=='E') l->op='F';
				else if (l->op=='I') l->op='X';
				else l->op='I';

				if (r->op=='F') r->op='E';
				else if (r->op=='E') r->op='F';
				else if (r->op=='I') r->op='X';
				else r->op='I';
			}
			else {
				l->op=op;
				r->op=op;
			}
		}
		op='X';
	}

	void modify(int _i, int _j, char _op) {
		visit();
		if (_i <= i && j <= _j) {
			op = _op;
			visit();
		}
		else if (_j < i || j < _i) { }
		else {
			l->modify(_i,_j,_op);
			r->modify(_i,_j,_op);
			val=l->val+r->val;
		}
	}

	int query(int _i, int _j) {
		visit();
		if (_i <= i && j <= _j) return val; 
		else if (_j < i || j < _i) return 0;
		else return l->query(_i,_j) + r->query(_i,_j);
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
		st.init(pirates,0,pirates.size()-1);

		int q; cin>>q;
		int queryCount=1;
		while (q--) {
			char op; int l, r;
			cin>>op>>l>>r;
			if (op!='S') st.modify(l,r,op);
			else cout << "Q" << queryCount++ << ": " << st.query(l,r) << '\n';
		}
	}
	return 0;
}
