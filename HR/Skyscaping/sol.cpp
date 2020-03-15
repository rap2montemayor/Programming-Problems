#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int i, j, val, temp;
	bool outOfBounds;
	segtree *l=NULL, *r=NULL;

	void init(vector<int> &ar, int _i, int _j) {
		i = _i; j = _j;
		temp = 0;
		outOfBounds = false;
		if (i == j) {
			val = ar[i];
			if (l!=NULL) {
				l->outOfBounds = true;
				r->outOfBounds = true;
			}
		}
		else {
			int k = (i+j)/2;
			if (l==NULL) {
				l = new segtree();
				r = new segtree();
			}
			l->init(ar, i, k);
			r->init(ar, k+1, j);
			val = l->val + r->val;
		}
	}

	void visit() {
		if (temp) {
			val += (j-i+1) * temp;
			if (l!=NULL) {
				l->temp += temp;
				r->temp += temp;
			}
			temp = 0;
		}
	}

	void update(int _i, int _j, int delta) {
		visit();
		if (_i <= i and j <= _j) {
			temp += delta;
			visit();
		} else if (_j < i or j < _i) { }
		else {
			l->update(_i, _j, delta);
			r->update(_i, _j, delta);
			val = l->val + r->val;
		}
	}

	int query(int _i, int _j) {
		visit();
		if (_i <= i and j <= _j) return val;
		else if (_j < i or j < _i) return 0;
		else return l->query(_i,_j) + r->query(_i,_j);
	}
};

vector<int> &moves;
int dp() {

}

int main() {

	return 0;
}
