#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	string s; cin>>s;
	
	stack<int> open, close;
	for (char i : s) {
		if (i=='(') {
			open.push('1');
		}
		else {
			if (!open.empty()) {
				open.pop();
			}
			else {
				close.push('1');
			}
		}
	}
	
	for (int i=0; i<close.size(); i++) cout << '(';
	cout << s;
	for (int i=0; i<open.size(); i++) cout << ')';
	cout << endl;
	return 0;
}
