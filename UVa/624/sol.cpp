#include <iostream>
#include <vector>
using namespace std;

int evalBitmask(int bitmask, vector<int> &arr) {
    int s = arr.size();
    int result = 0;
    for (int i = 0; i < s; i++)
        if (bitmask & (1 << i))
            result += arr[i];

    return result;
}

int subsetsum(vector<int> &arr, int max) {
    int s = arr.size();
    int maxbitmask = 0;

    int bitmask = 0;
    while (bitmask < 1 << s) {
        if (evalBitmask(bitmask, arr) > evalBitmask(maxbitmask, arr)
                and evalBitmask(bitmask, arr) <= max)
            maxbitmask = bitmask;
        bitmask++;
    }
    
    return maxbitmask;
}

int main() {
    int n, t;
    vector<int> tracks;

    while (cin >> n) {
        cin >> t;
        tracks.resize(t);
        for (int i = 0; i < t; i++)
            cin >> tracks[i];
        
        int bitmask = subsetsum(tracks, n);
        int sum = evalBitmask(bitmask, tracks);
        for (int i = 0; i < tracks.size(); i++)
            if (bitmask & (1 << i)) cout << tracks[i] << " ";
        cout << "sum:" << sum << endl;
        
        tracks.clear();
    }
    return 0;
}
