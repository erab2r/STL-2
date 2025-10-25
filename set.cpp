#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >>x;
        s.insert(x);
    // }
    // auto it = s.begin();
    // it++;
    // cout <<*it <<'\n';
    }
    for(auto value : s){
        cout << value <<' ';
    }
    cout << '\n';
    // auto it = s.find(25);
    // if(it != s.end()){
    //     cout << "Found" <<'\n';
    // }
    // else{
    //     cout << "Not Found" <<'\n';
    // }
    // s.erase(4);
    // for(auto value : s){
    //     cout << value <<' ';
    // }
    // cout << '\n';
    // cout << s.count(4) <<'\n';
    
    return 0;
}