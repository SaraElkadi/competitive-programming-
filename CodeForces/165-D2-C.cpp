#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    string s;
    cin>>k>>s;
    vector<long long> v;
    long long b[1000005]= {0};
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0')
            b[i]=b[max(i-1,0)]+1;
        else
            v.push_back(i);
    }
    v.push_back(s.size());
    long long ans=0;
    if(k!=0)
    {
        for(long long i=k-1; i+1<v.size(); i++)
        {
            ans+=((v[i-k+1]>0?b[v[i-k+1]-1]:0)+1)*(b[v[i+1]-1]+1);
        }
    }
    else
    {
        for(long long i=1; i<=s.size(); i++)
        {
            if(b[i]==0&&b[i-1]!=0)
            {
                ans+=(b[i-1]*(b[i-1]+1)/2);
            }
        }
    }
    cout<<ans;
    return 0;
}
