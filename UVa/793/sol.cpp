#include <bits/stdc++.h>
using namespace std;

struct union_find {
    vector<int> p;
    
    union_find(int n) {
        p = vector<int>(n,-1);
    }
    
    int find(int x) {
        if (p[x] < 0)
			return x;
		else {
			p[x] = find(p[x]);
			return p[x];
		}
    }

    bool unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp)
            return false;
        if (p[xp] > p[yp])
            swap(xp,yp);
        p[xp] += p[yp];
        p[yp] = xp;
        return true;
    }

    int size(int x) {
        return -p[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int computers; cin>>computers;
        union_find uf(computers+1);

        int success=0, fail=0;
        while (true) {
            char cmd;
            int a,b;
            cin>>cmd>>a>>b>>ws;
            if (cmd == 'c')
                uf.unite(a,b);
            else {
                if (uf.find(a) == uf.find(b))
                    success++;
                else
                    fail++;
            }

            if ((cin.peek() >= '0' and cin.peek() <= '9') or cin.eof())
                break;
        }
        cout << success << ',' << fail << "\n";
        if (t>0) cout << '\n';
    }
    return 0;
}