#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n%2==0||m<(n+1)/2)
        cout<<0;
    else{
        long long res=k*(m/((n+1)/2));
        for(int i=0;i<n;i+=2)
            res=min(res,a[i]);
        cout<<res;
    }
    return 0;
}
