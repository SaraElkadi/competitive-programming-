#include <bits/stdc++.h>

using namespace std;

const int MAX=1000005;

vector<bool> isprime(MAX,1);

void sieve()
{
    isprime[0]=isprime[1]=0;
    for(int i=2; i*i<MAX; i++)
    {
        if(isprime[i])
        {
            for(int j=i*2; j<MAX; j+=i)
                isprime[j]=0;
        }
    }
}

int main()
{
    sieve();
    vector<int> isDP(MAX,0);
    for(int i=0;i<MAX;i++){
        if(isprime[i]){
            int sum=0,n=i;
            while(n){
                sum+=n%10;
                n/=10;
            }
            if(isprime[sum])
                isDP[i]=1;
        }
        if(i)
            isDP[i]+=isDP[i-1];
    }
    
    int n,t1,t2;
    cin>>n;
    while(n--){
        cin>>t1>>t2;
        cout<<isDP[t2]-(t1>0?isDP[t1-1]:0)<<endl;
    }
    return 0;
}
