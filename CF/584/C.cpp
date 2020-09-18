#include <bits/stdc++.h>
using namespace std;

int getDiff(string &s1, string &s2) {
	int res = 0;
	for (int i = 0; i < s1.size(); ++i)
		if (s1[i] != s2[i]) ++res;
	return res;
}

string solve(string &s1, string &s2, int t) {
	int diff1 = 0, diff2 = getDiff(s1, s2);
	string res = s1;

	for (int i = 0; i < s1.size(); ++i) {
		if (diff2 >= t) break;
		if (s1[i] == s2[i]) {
			++diff1, ++diff2;
			if (s1[i] != 'a' and s2[i] != 'a')
				res[i] = 'a';
			else if (s1[i] != 'b' and s2[i] != 'b')
				res[i] = 'b';
			else
				res[i] = 'c';
		}
	}

	for (int i = 0; i < s1.size(); ++i) {
		if (diff2 <= t) break;
		if (s1[i] != s2[i]) {
			++diff1, --diff2;
			res[i] = s2[i];
		}
	}
	
	for (int i = 0; i < s1.size(); ++i) {
		if (diff1 == t) break;
		if (s1[i] != s2[i] and res[i] == s1[i]) {
			++diff1;
			if (s1[i] != 'a' and s2[i] != 'a')
				res[i] = 'a';
			else if (s1[i] != 'b' and s2[i] != 'b')
				res[i] = 'b';
			else
				res[i] = 'c';
		}
	}

	if (diff1 != t or diff2 != t)
		return "-1";
	else return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, t; cin >> n >> t;
	string s1, s2; cin >> s1 >> s2;
	cout << solve(s1, s2, t) << '\n';
	return 0;
}

