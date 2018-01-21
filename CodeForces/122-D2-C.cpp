#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long > v;
    v.push_back(4);
    v.push_back(7);
    int s=0,w=2;
    while(v[v.size()-1]<10000000000)
    {
        for(int i=s; i<s+w; i++)
        {
            v.push_back(v[i]*10+4);
            v.push_back(v[i]*10+7);
            if(v[i]>1000000000)
                break;
        }
        s+=w;
        w*=2;
    }
    int l,r,i,ss,e;
    cin>>l>>r;
    long long ans=0;
    if(l<=4&&r<=4)
    {
        cout<<(r-l+1)*4;
    }
    else
    {
        if(l<=4)
            ss=0;
        for(int i=1; i<v.size(); i++)
        {
            if(l<=v[i]&&l>v[i-1])
                ss=i;
            if(r<=v[i]&&r>v[i-1])
                e=i;
        }
        if(ss==e||r==l){
            cout<<v[ss]*(r-l+1);
        }
        else
        {
            ans=(v[ss]-l+1)*v[ss]+(r-v[e-1])*v[e];
            for(int i=ss+1; i<e; i++)
                ans+=(v[i]-v[i-1])*v[i];
            cout<<ans;
        }
    }
    return 0;
}

