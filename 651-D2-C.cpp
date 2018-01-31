#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y;
    map<int,int> mpx,mpy;
    map<pair<int,int>,int>mpp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        mpx[x]++;
        mpy[y]++;
        mpp[make_pair(x,y)]++;
    }
    long long ans=0;
    for(auto c:mpx){
        ans+=(long long)(c.second)*(c.second-1)/2;
    }
    for(auto c:mpy){
          ans+=(long long)(c.second)*(c.second-1)/2;
    }
    for(auto c:mpp){
        ans-=(long long)(c.second)*(c.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
