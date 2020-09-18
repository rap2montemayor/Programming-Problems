#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int,int>>> parts;
map<string, int> types;
int typecnt = 0;

void parseinput(int n) {
	string type, choice;
	int price, qual, itype;

	while (n--) {
		cin >> type >> choice >> price >> qual;
		if (types[type] == 0)
			types[type] = ++typecnt;

		itype = types[type];
		for (int i = 0; i < parts[itype].size(); ++i) {
			int compqual = parts[itype][i].first,
				compprice = parts[itype][i].second;

			if (compqual == qual and compprice > price) {
				parts[itype][i].second = price;
				itype = -1;
				break;
			}
		}
		if (itype != -1)
			parts[itype].push_back({qual, price});
	}

	for (int i = 1; i <= typecnt; ++i)
		sort(parts[i].begin(), parts[i].end());
}

int solve(int b) {
	int total = 0, res;
	vector<int> choices(typecnt + 1);

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	for (int i = 1; i < choices.size(); ++i) {
		total += parts[i][0].second;
		pq.push({parts[i][0].first, parts[i][0].second, i});
	}

	while (true) {
		int qual = pq.top()[0], price = pq.top()[1], type = pq.top()[2];
		res = qual;
		pq.pop();

		if (++choices[type] == parts[type].size()) break;
		if (total - price + parts[type][choices[type]].second <= b) {
			total = total - price + parts[type][choices[type]].second;
			qual = parts[type][choices[type]].first;
			price = parts[type][choices[type]].second;
			pq.push({qual, price, type});
		}
		else break;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, b; cin >> t;
	while (t--) {
		cin >> n >> b;
		parts.clear();
		types.clear();
		parseinput(n);
		cout << solve(b) << '\n';
	}
	return 0;
}

