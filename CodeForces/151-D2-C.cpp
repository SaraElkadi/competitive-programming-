#include <bits/stdc++.h>

using namespace std;
void sieve(){
vector<int> isprime(1e7+5,1);
isprime[0]=isprime[1]=0;
for(int i=2;i*i<=1e7;i++){
    if(isprime[i]){
        for(int j=i*i;j<=1e7;j+=i)
            isprime[j]=0;
    }
}
}
int main()
{
    long long n,N;
    cin>>n;
    N=n;
    vector<long long> v;
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
        if(v.size()>=2)
            break;
    }
    if(v.size()>=2&&v[0]*v[1]!=N)
        cout<<1<<endl<<v[0]*v[1]<<endl;
    else if(v.size()==0)
        cout<<1<<endl<<0<<endl;
    else
        cout<<2<<endl;
    return 0;
}
