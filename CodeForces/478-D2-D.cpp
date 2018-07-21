#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int dp[2][200005],t,r,g;

int solve(int mx) {
	int res=0;
	dp[0][0]=1;
	for (int i=1;i<=mx;i++){
		for (int j=0;j<=r;j++){
			dp[i%2][j]=dp[(i+1)%2][j]%mod;
			if (j-i>=0)
				dp[i%2][j]=(dp[i%2][j]+dp[(i+1)%2][j-i])%mod;
		}
	}
	for(int i=0;i<=r;i++){
		if (i+g>=t)
			res=(res+dp[mx%2][i])%mod;
	}
	return res;
}

int main()
{
    cin>>r>>g;
	int mx=0,cnt=1;
	while (t+cnt<=r+g)
		mx++,t+=cnt++;
    cout<<solve(mx)<<endl;
    return 0;
}
