#include <bits/stdc++.h>
using namespace std;

struct node {
	node *l = NULL, *r = NULL;
	char val;
};

struct linked_list {
	node *left = NULL, *right = NULL;

	linked_list(string &s) {
		node *n = new node();
		n->val = s[0];
		left = right = n;
		for (int i = 1; i < s.size(); ++i)
			push_right(s[i]);
	}

	void push_left(char c) {
		node *n = new node();
		n->val = c;
		n->r = left;
		left->l = n;
		left = n;
	}	

	void push_right(char c) {
		node *n = new node();
		n->val = c;
		n->l = right;
		right->r = n;
		right = n;
	}	
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int q; cin >> q;

	linked_list ll(s);
	bool rev = false;
	int t, f;
	char c;
	for (int i = 0; i < q; ++i) {
		cin >> t;
		if (t == 1)
			rev = not rev;
		else {
			cin >> f >> c;
			if ((not rev and f == 1) or (rev and f == 2))
				ll.push_left(c);
			if ((not rev and f == 2) or (rev and f == 1))
				ll.push_right(c);
		}
	}

	node *n;
	if (rev) {
		n = ll.right;
		while (n != NULL) {
			cout << n->val;
			n = n->l;
		}
	}
	else {
		n = ll.left;
		while (n != NULL) {
			cout << n->val;
			n = n->r;
		}
	}
	cout << '\n';

	return 0;
}