#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k,a,x,sum=0,sz=1;
    vector<long long> v;
    int w[200005]= {0};
    v.push_back(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>k;
        if(k==1)
        {
            cin>>a>>x;
            w[a]+=x;
            sum+=a*x;
        }
        else if(k==2)
        {
            cin>>x;
            v.push_back(x);
            sum+=x;
            sz++;
        }
        else if(k==3)
        {
            if(sz>=2)
            {
                sum-=w[sz];
                w[sz-1]+=w[sz];
                w[sz]=0;
                sum-=v.back();
                v.pop_back();
                sz--;
            }
        }
        cout<<fixed<<setprecision(6)<<(double)sum/sz<<endl;
    }
    return 0;
}
