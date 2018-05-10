#include <bits/stdc++.h>

using namespace std;
set<long long> v,ans;
vector<long long> era;
long long ss;
int n,m,c;
char xs[100];
void solve(int idx,int k,long long s)
{
    if(k>c)
        return;
    if(idx==n)
    {
        if(k==c)
            v.insert(s);
        return;
    }
    solve(idx+1,k+1,s+((ss>>idx&1)<<idx));
    solve(idx+1,k,s+(((ss>>idx&1)^1)<<idx));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        v.clear(),era.clear();
        scanf("%s%d",xs,&c);
        ss=0;
        for(int i=0; i<n; i++)
            ss=(ss<<1)+xs[i]-'0';
        solve(0,0,0);
        if(i==0)
            ans=v;
        else
        {
            for(auto q:ans)
            {
                if(v.find(q)==v.end())
                    era.push_back(q);
            }
            for(int j=0; j<era.size(); j++)
                ans.erase(era[j]);
        }
    }
    printf("%d",ans.size());
    return 0;
}
