#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x,y;
    while(cin>>x>>y){
        if(x=="0"||y=="0"){
            cout<<"0\n";
            continue;
        }
        int c=0,s=0;
        int ans[550]={0};
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                ans[i+j]+=(x[i]-'0')*(y[j]-'0');
                if(i||j){
                    ans[i+j]+=ans[i+j-1]/10;
                    ans[i+j-1]%=10;
                }
            }
            ans[i+y.size()]+=ans[i+y.size()-1]/10;
            ans[i+y.size()-1]%=10;
        }
        int e=505;
        while(ans[e]==0)
            e--;
        for(int i=e;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
