#include <bits/stdc++.h>
using namespace std;
int m = 1e9+7;

int main() {
	int n; cin>>n;
	vector<map<string,int>> dp(101);
	vector<string> disallowed = {"AGC","GAC","ACG","AGGC","AGTC","ATGC"};
	string s = "ACGT";

	dp[0]["XXXX"] = 1;
	for (int i=0; i<100; i++) {
		for (pair<string,int> p: dp[i]) {
			for (char c : s) {
				string last4 = p.first.substr(1,3) + c;
				string last3 = last4.substr(1,3);
				bool skip = false;
				for (string x : disallowed) {
					if (x==last4 or x==last3) {
						skip = true;
						break;
					}
				}
				if (skip) continue;
				dp[i+1][last4] = (dp[i+1][last4]%m + p.second%m)%m;
			}
		}
	}

	int ans=0;
	for (pair<string, int> p : dp[n])
		ans = (ans%m + p.second%m)%m;
	cout << ans << endl;
	
	return 0;
}
