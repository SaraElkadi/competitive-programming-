#include <iostream>
#include<iomanip>

using namespace std;

const int N=1005;
double dp[N][N];

int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=n;i>=0;i--)
        for(int j=s;j>=0;j--)
            if(i!=n||j!=s)
                dp[i][j]=(n*s+dp[i+1][j]*(n-i)*j+dp[i][j+1]*i*(s-j)+dp[i+1][j+1]*(n-i)*(s-j))/(n*s-i*j);
    
    cout<<fixed<<setprecision(4)<<dp[0][0]<<endl;
    
    return 0;
}
