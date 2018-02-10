#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<(n*6-1)*k<<endl;
    int w=0;
    for(int i=1;i<=(n*6-1);i++){
        if((i-4)%6!=0&&i%6!=0){
            cout<<i*k<<" ";
            w++;
        }
        if(w==4){
            cout<<endl;
            w=0;
        }
    }
    return 0;
}
