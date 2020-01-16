#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> costs = {0,2,5,5,4,5,6,3,7,6};

bool comp(vector<int> &a, vector<int> &b) {
	int alen=0, blen=0;
	for (int i : a) alen+=i;
	for (int i : b) blen+=i;
	
	if (alen > blen) return true;
	else if (alen==blen) {
		for (int i=9; i>0; i--) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
	}
	return false;
}

int getLen(vector<int> &v) {
	int res=0;
	for (int i=1; i<=9; i++)
		res+=costs[i]*v[i];
	return res;
}

int main() {
	int n,m; cin>>n>>m;
	vector<int> a(m);
	dp.resize(n+1,vector<int>(10));
	for (int i=0; i<m; i++)
		cin>>a[i];
	
	//bot-up
	//O(pray to the algo gods that this is efficient enough)
	for (int i=0; i<=n; i++) {
		for (int x : a) {
			if (costs[x]<=i) {
				vector<int> temp(dp[i-costs[x]]);
				temp[x]+=1;
				if (getLen(temp)==i) {
					if (comp(temp,dp[i]))
						dp[i] = vector<int>(temp);
				if (comp(dp[i-costs[x]],temp))
					dp[i] = vector<int>(dp[i-costs[x]]);
				}
			}
		}
	}

	vector<int> ans = dp.back();
	for (int i=9; i>0; i--)
		for (int x=0; x<ans[i]; x++)
			cout << i;
	cout << endl;
	return 0;
}
