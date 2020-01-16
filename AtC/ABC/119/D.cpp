#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll a,b,q; cin>>a>>b>>q;
	vector<ll> s(a), t(b), x(q);
	for (ll i=0; i<a; i++) cin>>s[i];
	for (ll i=0; i<b; i++) cin>>t[i];
	for (ll i=0; i<q; i++) cin>>x[i];
	
	for (ll i : x) {
		vector<ll>::iterator shrine, temple;
		
		ll ans=~(1LL<<63);
		//shrine then temple
		shrine = lower_bound(s.begin(),s.end(),i);
		if (shrine!=s.end()) {
			temple = lower_bound(t.begin(),t.end(),*shrine);
			if (temple!=t.end()) {
				if (abs(i-*shrine) + abs(*shrine-*temple) < ans) {
					ans = abs(i-*shrine) + abs(*shrine-*temple);
					//cout << ' ' << ans << endl;
				}
			}
			if (temple!=t.begin()) {
				temple--;
				if (abs(i-*shrine) + abs(*shrine-*temple) < ans) {
					ans = abs(i-*shrine) + abs(*shrine-*temple);
					//cout << ' ' << ans << endl;
				}
			}
		}

		if (shrine!=s.begin()) {
			shrine--;
			temple = lower_bound(t.begin(),t.end(),*shrine);
			if (temple!=t.end()) {
				if (abs(i-*shrine) + abs(*shrine-*temple) < ans) {
					ans = abs(i-*shrine) + abs(*shrine-*temple);
					//cout << ' ' << ans << endl;
				}
			}
			if (temple!=t.begin()) {
				temple--;
				if (abs(i-*shrine) + abs(*shrine-*temple) < ans) {
					ans = abs(i-*shrine) + abs(*shrine-*temple);
					//cout << ' ' << ans << endl;
				}
			}
		}

		temple = lower_bound(t.begin(),t.end(),i);
		if (temple!=t.end()) {
			shrine = lower_bound(s.begin(),s.end(),*temple);
			if (shrine!=s.end()) {
				if (abs(i-*temple) + abs(*temple-*shrine) < ans) {
					ans = abs(i-*temple) + abs(*temple-*shrine);
					//cout << ' ' << ans << endl;
				}
			}
			if (shrine!=s.begin()) {
				shrine--;
				if (abs(i-*temple) + abs(*temple-*shrine) < ans) {
					ans = abs(i-*temple) + abs(*temple-*shrine);
					//cout << ' ' << ans << endl;
				}
			}
		}

		if (temple!=t.begin()) {
			temple--;
			shrine = lower_bound(s.begin(),s.end(),*temple);
			if (shrine!=s.end()) {
				if (abs(i-*temple) + abs(*temple-*shrine) < ans) {
					ans = abs(i-*temple) + abs(*temple-*shrine);
					//cout << ' ' << ans << endl;
				}
			}
			if (shrine!=s.begin()) {
				shrine--;
				if (abs(i-*temple) + abs(*temple-*shrine) < ans) {
					ans = abs(i-*temple) + abs(*temple-*shrine);
					//cout << ' ' << ans << endl;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
