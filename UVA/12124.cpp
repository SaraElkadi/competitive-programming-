/* apply binary search algorithm to find the maximum quality 
   at each value of quality , calculate the mimimum money need to get the quality and depened on that change the high 
   or the low side of the range with the mid value.
   */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,k,q,p;
    string name,type;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<vector<pair<int,int>>> v(1005);
        map<string,int> mp;
        int cnt=1,l=0,r=1e9,ans=0,mid,mn,sum;
        while(n--)
        {
            cin>>name>>type>>p>>q;
            if(!mp[name])
            {
                mp[name]=cnt++;
            }
            int x=mp[name];
            v[x].push_back(make_pair(p,q));
        }
        while(l<=r)
        {
            mid=(l+r)/2;
            sum=0;
            for(int i=1; i<cnt; i++)
            {
                mn=1e9;
                for(int j=0; j<v[i].size(); j++)
                {
                    if(v[i][j].second>=mid)
                        mn=min(mn,v[i][j].first);
                }
                sum+=mn;
                if(sum>k)
                    break;
            }
            if(sum<=k)
                l=mid+1,ans=max(ans,mid);
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
