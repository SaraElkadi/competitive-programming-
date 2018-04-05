#include <bits/stdc++.h>

using namespace std;
const int MAX =1e6+5;
long long r[MAX],c[MAX];
int main()
{
    long long n,m,k,p;
    cin>>n>>m>>k>>p;
    long long a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    priority_queue<long long,vector<long long>,less<long long>> q1,q2;
    for(int i=0; i<n; i++)
    {
        long long sum=0;
        for(int j=0; j<m; j++)
            sum+=a[i][j];
        q1.push(sum);
    }
    for(int j=0; j<m; j++)
    {
        long long sum=0;
        for(int i=0; i<n; i++)
            sum+=a[i][j];
        q2.push(sum);
    }
    for(int i=1;i<=k;i++){
        long long x=q1.top();
        r[i]=r[i-1]+x;
        q1.pop();
        q1.push(x-p*m);
    }
    for(int i=1;i<=k;i++){
        long long x=q2.top();
        c[i]=c[i-1]+x;
        q2.pop();
        q2.push(x-p*n);
    }

    long long ans=-4e18;
    for(int i=0;i<=k;i++){
        ans=max(ans,r[i]+c[k-i]-i*(k-i)*p);
    }
    cout<<ans;
    return 0;
}
