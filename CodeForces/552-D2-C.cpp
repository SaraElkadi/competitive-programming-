#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long w,m;
    cin>>w>>m;
    int b[105]={0},i=0;
    while(m){
        b[i++]=m%w;
        m/=w;
    }
    bool f=1;
    for(int i=0;i<100;i++){
        if(b[i]!=0&&b[i]!=1){
           b[i]-=w;
           b[i+1]++;
           if(b[i]!=0&&b[i]!=-1){
            f=0;
            break;
           }
        }
    }
    if(f)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

