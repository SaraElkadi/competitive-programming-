#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
vector<int> v;
int mat[705];
string s;
long long dp[705][3][3];

long long solve(int idx,int bef,int aft)
{
    if(idx==s.size()||s[idx]==')')
        return 1;
    long long &ret=dp[idx][bef][aft];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((i&&j)||(!i&&!j))
                continue;
            if(idx>0&&i&&i==bef)
                continue;
            if(mat[idx]<s.size()-1&&s[mat[idx]+1]==')'&&j&&j==aft)
                continue;
            ret+=solve(idx+1,i,j)*solve(mat[idx]+1,j,aft);
            ret%=mod;
        }
    }
    return ret;
}

int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            v.push_back(i);
        else
        {
            mat[v.back()]=i;
            v.pop_back();
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0,0);
    return 0;
}
