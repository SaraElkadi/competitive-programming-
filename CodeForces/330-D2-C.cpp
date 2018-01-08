#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s[n];
    bool r=1,c=1;
    for(int i=0;i<n;i++){
        cin>>s[i];
        bool f=1;
        for(int j=0;j<n;j++){
            if(s[i][j]=='.')
                f=0;
        }
        if(f)
            r=0;
    }
    for(int j=0;j<n;j++){
            bool f=1;
        for(int i=0;i<n;i++){
            if(s[i][j]=='.')
                f=0;
        }
        if(f)
            c=0;
    }
    if(!r&&!c)
        cout<<-1;
    else if(!c){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='.'){
                    cout<<i+1<<" "<<j+1<<endl;
                    break;
                }
            }
        }
    }
    else{
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(s[i][j]=='.'){
                    cout<<i+1<<" "<<j+1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
