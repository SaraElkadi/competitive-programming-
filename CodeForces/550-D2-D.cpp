#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<4*n-2<<" "<<(n-1)*(2*n+1)+1<<endl;
    for(int i=2;i<=n;i++){
        cout<<1<<" "<<i<<endl;
        cout<<2*n<<" "<<i+2*n-1<<endl;
    }
    for(int i=2;i<=n;i++){
        for(int j=n+1;j<2*n;j++){
            cout<<i<<" "<<j<<endl;
            cout<<i+2*n-1<<" "<<j+2*n-1<<endl;
        }
    }
    for(int i=n+1;i<2*n;i+=2){
        cout<<i<<" "<<i+1<<endl;
        cout<<i+2*n-1<<" "<<i+2*n<<endl;
    }
    cout<<1<<" "<<2*n<<endl;
    return 0;
}
