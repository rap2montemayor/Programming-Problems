#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<string> strings(n);
	for (int i=0; i<n; i++) cin>>strings[i];
	sort(strings.begin(), strings.end(), [](string s1, string s2){return s1+s2<s2+s1;});
	for (string s : strings) cout << s; cout << endl;
	return 0;
}
