#include <bits/stdc++.h>

using namespace std;
int n,a[105],b[105];
bool solve(int k)
{
    for(int i=1; i<=k; i++)
        b[i]=a[n-i+1];
    int j=1;
    for(int i=n-k; i>0; i--)
    {
        b[j]=min(b[j]-1,a[i]);
        j++;
        if(j>k)
            j=1;
    }
    for(int i=1; i<=k; i++)
    {
        if(b[i]<0)
            return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=100; i++)
    {
        if(solve(i))
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
