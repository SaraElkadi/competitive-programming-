#include <bits/stdc++.h>

using namespace std;
int mem[55][55];
vector<int> v;
int dp(int s,int e)
{
    if(s+1==e) return 0;
    if(mem[s][e]!=-1)
        return mem[s][e];
    int x=500000;
    for(int i=s+1; i<e; i++)
        x=min(x,dp(s,i)+dp(i,e)+v[e]-v[s]);
    return mem[s][e]=x;
}
int main()
{
    int l,n,a;
    while(cin>>l&&l)
    {
        cin>>n;
        v.clear();
        v.push_back(0);
        for(int i=0; i<n; i++)
        {
            cin>>a;
            v.push_back(a);
        }
        v.push_back(l);
        memset(mem,-1,sizeof mem);
        cout<<"The minimum cutting is "<<dp(0,n+1)<<".\n";
    }
    return 0;
}
