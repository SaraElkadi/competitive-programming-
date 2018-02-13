#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,K,p,q;
    cin>>n>>K>>p;
    bool f=0;
    if(n%2&&K>0){
        n--;
        K--;
    }
    else if(n%2){
        n--;
        f=1;
    }
    for(int i=0; i<p; i++)
    {
        cin>>q;
        if(q==n+1&&!f)
        {
            cout<<'X';
            continue;
        }
        else if(q==n+1){
            cout<<'.';
            continue;
        }
        long long k=K;
        if(q%2==0)
        {
            if(((n/2+1)-q/2)<=k)
                cout<<'X';
                else
                    cout<<'.';
        }
        else
        {
            if(n/2>=k)
                cout<<".";
            else
            {
                k-=n/2;
                 if(((n/2)-q/2)<=k)
                    cout<<'X';
                else
                    cout<<'.';
            }
        }
    }
    return 0;
}
