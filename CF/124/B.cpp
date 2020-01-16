#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int ans = numeric_limits<int>::max();

void f(vector<string> &nums, int size) {
    if (size == 1) {
        //do comparisons
        int max = stoi(nums[0]);
        int min = stoi(nums[0]);
        for (string s : nums) {
            if (stoi(s) > max) max = stoi(s);
            if (stoi(s) < min) min = stoi(s);
        }
        if (max-min < ans) ans = max-min;
    }
    else {
        f(nums, size-1);
        for (int i = 0; i < size-1; i++) {
            if (size%2) {
                for (int j = 0; j < nums.size(); j++) {
                    //swap 0, size-1
                    char temp = nums[j][0];
                    nums[j][0] = nums[j][size-1];
                    nums[j][size-1] = temp;
                }
            }
            else {
                for (int j = 0; j < nums.size(); j++) {
                    //swap i, size-1
                    char temp = nums[j][i];
                    nums[j][i] = nums[j][size-1];
                    nums[j][size-1] = temp;
                }
            }
            f(nums, size-1);
        }
    }
}

int main() {
    int n, k;
    vector<string> nums;

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nums.push_back(s);
    }

    f(nums, k);
    cout << ans << endl;
    return 0;
}
