#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll getShellElectrons(ll n) {
	ll m = (n+1)/2, x = 2*m*m;
	ll y = (8*m*m*m + 12*m*m + 4*m)/6;
	//ll y = 4*m*(m+1)*(2*m+1)/6;
	if (n%2) y-=x;
	return y;
}
 
ll getShell(ll n) {
	ll l=0, r=1000000;
	while (l<r) {
		ll m = (l+r)/2;
		ll x = getShellElectrons(m);
		if (x<n) l=m+1;
		else if (x>n) r=m;
		else return m;
	}
	return l;
}
 
ll getSubshell(ll shell, ll unfilled) {
	ll l=0, r=shell;
 
	while (l<r) {
		ll m = (l+r)/2;
		ll x = unfilled-2*m*m;
		if (x>0) l=m+1;
		else if (x<0) r=m;
		else return m;
	}
	return l;
}
 
string subshellLetters="spdfghijklmnoqrtuvwxyz";
string letters="abcdefghijklmnopqrstuvwxyz";
string getSubshellLetter(ll subshell) {
	if (subshell<=22)
		return string(1,subshellLetters[subshell-1]);
	subshell += 4;
	ll pow=1, temp=0, digits=0;
	while (temp<subshell) {
		digits+=1;
		temp += pow*26;
		pow*=26;
	}
	string res(digits,'a');
	while (digits>0) {
		digits-=1, subshell-=1;
		res[digits] = letters[subshell%26];
		subshell/=26;
	}
 
	return res;
}
 
int main() {
	ll t; cin>>t;
	while (t--) {
		ll a; cin>>a;
		ll shell = getShell(a);
		ll shellElectrons = getShellElectrons(shell);
		ll subshell = getSubshell(shell, shellElectrons-a);
		if (-(shellElectrons-a-2*subshell*subshell)==0)
			subshell++;
 
		cout << shell-subshell+1
			 << getSubshellLetter(subshell)
			 << -(shellElectrons-a-2*subshell*subshell) << endl;
	}
	return 0;
}
