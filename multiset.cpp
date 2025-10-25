#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0;i<=n;i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    
    // auto it = ms.begin();
    // it++;
    // it++;
    // cout << *it << '\n';
}