#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int skillCount[int(2e5+1)];
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        memset(skillCount,0,sizeof skillCount);

        for (int i=0; i<n; i++) {
            int s; cin>>s;
            skillCount[s]++;
        }

        int team1=0, team2=0, team2Skill=-1;
        for (int i=0; i<=n; i++) {
            if (skillCount[i] > team2) {
                team2 = skillCount[i];
                team2Skill = i;
            }
        }
        for (int i=0; i<=n; i++) {
            if (skillCount[i] > 0) {
                team1++;
                if (i==team2Skill)
                    team1--;
            }
        }

        int ans = min(team1,team2);
        ans = max(ans, min(team1+1,team2-1));
        cout << ans << '\n';
    }
    return 0;
}