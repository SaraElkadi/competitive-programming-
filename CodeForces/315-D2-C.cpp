#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    long long a[n+5];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    long long num=0,sum=0,d=0;
    for(int i=1; i<=n; i++)
    {
        if(d<k)
            cout<<i<<endl;
        else
        {
            sum+=(a[i]*num);
            num++;
        }
        d=sum-num*(n-i-1)*a[i+1];
    }

    return 0;
}
