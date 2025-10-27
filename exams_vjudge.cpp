#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  
    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z; 

        int totalStudents = X * Y;

        if (Z * 2 > totalStudents) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
