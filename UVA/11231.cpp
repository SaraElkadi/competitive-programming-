#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,c;
    while(cin>>n>>m>>c&&(n||m||c)){
        int x=(n-7)*(m-7);
        cout<<x/2+(c&&x%2?1:0)<<endl;
    }
    return 0;
}
