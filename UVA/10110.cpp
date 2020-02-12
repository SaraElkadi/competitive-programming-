#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    while(cin>>n&&n){
        long long i;
        for(i=1;i*i<n;i++);
        if(i*i==n)
           cout<<"yes\n";
        else
           cout<<"no\n";
    }
    return 0;
}
