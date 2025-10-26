#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // map<vector<int>,int> mp;
    
    // vector<int> e;
    // e.push_back(2);
    // e.push_back(4);
    // e.push_back(7);
    // e.push_back(8);
    // e.push_back(9);
    // mp[e] = 10;
    // for(auto [x,y]: mp){
    //     vector<int> v = x;
    //     for(auto value: v){
    //         cout << value << ' ';
    //     }
    //     cout <<'\n';
    //     cout << y << '\n';
    // }
    map<int, set<int>> mp;
    set<int> s;
    s.insert(2);
    s.insert(4);
    s.insert(7);

    set<int> s2;
    s2.insert(9);
    s2.insert(4);
    s2.insert(6);

    set<int> s3;
    s3.insert(2);
    s3.insert(9);
    s3.insert(8);

    mp[2] = s;
    mp[7] = s2;
    mp[8] = s3;

    for(auto [x,y]: mp){
            cout << x << "->";
            for(auto value: y){
                cout << value << ' ';
            }
             cout << '\n';
    }
    int x = 6, y = 8;
   auto LB1 = mp.lower_bound(x);
   if (LB1 != mp.end()) {
      int ans = LB1->first;
      cout << ans << '\n';
      auto LB2 = mp[ans].lower_bound(y);
      if (LB2 != mp[ans].end()) {
         cout << *LB2 << '\n';
      }
      else {

      }
   }
   else {

   }
   return 0;
}