#include <bits/stdc++.h>

using namespace std;
const long long mod=1000000007;
int main()
{
    long long t,a,b,c,n,m;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        priority_queue<int,vector<int>,less<int>> l;
        priority_queue<int,vector<int>,greater<int>> r;
        l.push(1);
        long long sum=1,nl=1,nr=0,f=1;
        for(long long i=2;i<=n;i++){
            m=l.top();
            f=(a*m+b*i+c)%mod;
            sum+=f;
            if(nl>nr){
                if(f>=m)
                    r.push(f);
                else{
                    l.pop();
                    r.push(m);
                    l.push(f);
                }
                nr++;
            }
            else{
                m=r.top();
                if(f<=m)
                    l.push(f);
                else{
                    r.pop();
                    l.push(m);
                    r.push(f);
                }
                nl++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
