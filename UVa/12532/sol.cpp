#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int n; int *vals;
	
	segtree(vector<int> &ar, int n) {
		this->n = n;
		vals = new int[2*n];
		for (int i=0; i<n; i++)
			vals[i+n] = ar[i];
		for (int i=n-1; i>0; i--)
			vals[i] = vals[i<<1] * vals[i<<1|1];
	}

	void update(int i, int v) {
		for (vals[i+=n] = v; i>1; i>>=1)
			vals[i>>1] = vals[i] * vals[i^1];
	}

	int query(int l, int r) {
		int res=1;
		for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
			if (l&1) res*=vals[l++];
			if (r&1) res*=vals[--r];
		}
		return res;
	}
};

int main() {
	int n,k;
	
	while (cin>>n>>k) {
		vector<int> x(n);
		for (int i=0; i<n; i++) {
			cin>>x[i];
			if (x[i] > 0) x[i] = 1;
			else if (x[i] < 0) x[i] = -1;
			else x[i] = 0;
		}
		segtree st(x,n);

		while (k--) {
			char cmd;
			int arg1, arg2;
			cin>>cmd>>arg1>>arg2;
			if (cmd=='C') {
				if (arg2>0) arg2=1;
				else if (arg2<0) arg2=-1;
				else arg2=0;
				st.update(arg1-1,arg2);
			}
			else {
				int res = st.query(arg1-1,arg2-1);
				if (res == 1) cout << '+';
				else if (res == -1) cout << '-';
				else cout << '0';
			}
		}
		cout << endl;
	}
	return 0;
}
