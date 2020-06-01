#include <bits/stdc++.h>
using namespace std;

bool eval(vector<int> &nums, int idx, int res) {
    if (idx >= nums.size()) return res == 23;
    bool res1 = eval(nums, idx+1, res+nums[idx]);
    bool res2 = eval(nums, idx+1, res-nums[idx]);
    bool res3 = eval(nums, idx+1, res*nums[idx]);

    return res1 or res2 or res3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> allzeroes({0, 0, 0, 0, 0});
    while (true) {
        vector<int> nums(5);
        for (int i=0; i<5; i++) cin>>nums[i];
        if (nums == allzeroes) break;
        bool possible = false;
        for (int i=0; i<120; i++) {
            if (possible) break;
            possible = possible or eval(nums, 1, nums[0]);
            next_permutation(nums.begin(), nums.end());
        }

        possible ? cout << "Possible\n" : cout << "Impossible\n";
    }
    return 0;
}