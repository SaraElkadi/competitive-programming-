#include <bits/stdc++.h>

using namespace std;

const int MAX=105;

vector<int> prime;

void sieve()
{
    vector<bool> isprime(MAX,1);
    isprime[0]=isprime[1]=0;
    for(int i=2; i*i<MAX; i++)
    {
        if(isprime[i])
        {
            for(int j=i*2; j<MAX; j+=i)
                isprime[j]=0;
        }
    }
    for(int i=0; i<MAX; i++)
    {
        if(isprime[i])
           prime.push_back(i);
    }
}

int main()
{
    sieve();
    int n;
    while(cin>>n&&n!=0)
    {
        cout<<setw(3)<<n<<"! =";
        int p=0;
        while(prime[p]<=n)
        {
            if(p!=0&&p%15==0)
                cout<<endl<<string(6,' ');
            int cnt=0;
            for(int i=prime[p]; i<=n; i*=prime[p])
                cnt+=n/i;
            cout<<setw(3)<<cnt;
            p++;
        }
        cout<<endl;
    }
    return 0;
}
