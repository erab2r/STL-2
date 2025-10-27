#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    map<int, tuple<int, int, int>> mp; 
    for (int i = 0; i <tc; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[i] = make_tuple(x, y, z);
    }
    for (auto &[idx, t] : mp) {
        int x, y, z;
        tie(x, y, z) = t;
        int total_t = x * y;        
        int store_time = z * 24 * 60; 
        if (total_t <= store_time)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
