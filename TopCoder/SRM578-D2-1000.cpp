#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
int n;
int dp[305][305];
vector<vector<int>> v(305);

class WolfInZooDivTwo
{    
public:
    int solve(int idx,int last)
    {
        if(idx>n)
            return 1;
        int &ret=dp[idx][last];
        if(ret!=-1)
            return ret;
        ret=0;
        bool f=1;
        for(int i=0; i<v[idx].size(); i++)
        {
            if(v[idx][i]>last)
            {
                f=0;
                break;
            }
        }
        if(f)
            ret+=solve(idx+1,last);
        ret+=solve(idx+1,idx);
        ret%=mod;
        return ret;
    }

    int count(int N, vector<string> L, vector<string> R)
    {
        for(int i=0; i<=N; i++)
            v[i].clear();
        memset(dp,-1,sizeof dp);
        string l="",r="";
        for(int i=0; i<L.size(); i++)
            l+=L[i];
        for(int i=0; i<R.size(); i++)
            r+=R[i];
        stringstream ll(l),rr(r);
        int a,b;
        while(rr>>a)
        {
            ll>>b;
            v[a+1].push_back(b+1);
        }
        n=N;
        return solve(1,0);
    }
};

