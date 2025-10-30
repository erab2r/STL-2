#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,m;
        cin >> n >> m;
        map<int,set<int>> mp;
        for(int i = 1;i<=n;i++){
            int x;
            cin >> x;
            mp[x].insert(i);
        }
        // for(auto [x,y] : mp){
        //     cout << x << "->";
        //     for(auto value : y){
        //         cout << value <<" ";
        //     }
        //     cout<<'\n';
        // }
        for (int i = 1;i <= m;i++) {
         int l, r;
         cin >> l >> r;
         if ((mp.find(l) == mp.end()) || (mp.find(r) == mp.end())) {
            cout << "NO" << '\n';
         }
         else {
            int starting_Station_Left_Most_Index, ending_Station_RightMostIndex;
            starting_Station_Left_Most_Index = *mp[l].begin();
            ending_Station_RightMostIndex = *mp[r].rbegin();
            if (starting_Station_Left_Most_Index < ending_Station_RightMostIndex) {
               cout << "YES" << '\n';
            }
            else {
               cout << "NO" << '\n';
            }
         }
      }
   }

   return 0;
}