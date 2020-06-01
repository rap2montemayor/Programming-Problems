#include <bits/stdc++.h>
using namespace std;

struct team_queue {
    vector<queue<int>> vq;
    queue<int> q;
    vector<int> idx;
    map<int,int> teamOf;
    int teamCount = 0;

    team_queue(int teams) {
        vq = vector<queue<int>>(teams);
        idx = vector<int>(teams,-1);
        q = queue<int>();
    }

    void enlist(int n, int team) {
        teamOf[n] = team;
    }

    void enqueue(int n) {
        int team = teamOf[n];
        if (idx[team] == -1) {
            idx[team] = teamCount++;
            q.push(team);
        }
        vq[team].push(n);
    }

    int dequeue() {
        int ret = vq[q.front()].front();
        vq[q.front()].pop();
        if (vq[q.front()].empty()) {
            idx[q.front()] = -1;
            q.pop();
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, scenario = 1;
    while (cin>>n) {
        if (n==0) break;
        team_queue tq(n);
        for (int i=0; i<n; i++) {
            int m; cin>>m;
            for (int j=0; j<m; j++) {
                int member; cin>>member;
                tq.enlist(member,i); 
            }
        }

        cout << "Scenario #" << scenario << '\n';
        string cmd;
        while (cin>>cmd) {
            if (cmd == "ENQUEUE") {
                int arg; cin>>arg;
                tq.enqueue(arg);
            }
            else if (cmd == "DEQUEUE") {
                cout << tq.dequeue() << endl;
            }
            else break;
        }
        cout << '\n';

        scenario++;
    }
    return 0;
}