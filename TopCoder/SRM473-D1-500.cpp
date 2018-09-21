#include <bits/stdc++.h>

using namespace std;

class RightTriangle
{
public:
    long triangleCount(int pl, int pnt, int a, int b, int c)
    {
        if(pl%2)
            return 0;
        vector<bool> vis(1000005,0);
        vector<int> v;
        for(long long i=0; i<pnt; i++)
        {
            long long x=((((a%pl)*(((i%pl)*(i%pl))%pl))%pl)+(((b%pl)*(i%pl))%pl)+(c%pl))%pl;
            int  j=x;
            while(vis[j])
            {
                j++;
                j%=pl;
                if(j==x)
                    break;
            }
            if(!vis[j])
            {
                v.push_back(j);
                vis[j]=1;
            }
            else
                break;
        }
        long long ans=0;
        sort(v.begin(),v.end());
        for(int i=0; i<v.size()&&v[i]<=pl/2; i++)
        {
            if(vis[v[i]+pl/2])
                ans+=(long long)v.size()-2;
        }
        return ans;
    }
};
