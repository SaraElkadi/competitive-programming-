#include <bits/stdc++.h>

using namespace std;

const int MAX=1000005;

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
    long long n;
    while(cin>>n&&n!=-1){
        for(int p=0;p<prime.size();p++){
            while(n%prime[p]==0){
                cout<<string(4,' ')<<prime[p]<<endl;
                n/=prime[p];
            }
        }
        if(n!=1)
            cout<<string(4,' ')<<n<<endl;
        cout<<endl;
    }
    return 0;
}
