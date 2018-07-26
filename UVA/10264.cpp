
/*
   First ,Get the potency of reach corner .
   To get all neighbouring corners , flip one of the bits of index and the result would be one the indexes of neighbouring corners.
   Fliping can be done easily by XOR the bit you want to flip with one.
   After that get the sum of potency for each two neighbouring corners and the answer would the max value .
   To know if this two corners are neighbouring or not , the indexes of them should have exactly one bit different . 
   To check this , XOR the indexes and check if the answer is equal to 2^i or not .
   */


#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> p;
    int x=1;
    for(int i=0; i<15; i++)
    {
        p.push_back(x);
        x*=2;
    }
    int n;
    while(cin>>n)
    {
        int a[(1<<n)],b[(1<<n)];
        for(int i=0; i<(1<<n); i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<(1<<n); i++)
        {
            b[i]=0;
            for(int j=0; j<n; j++)
            {
                b[i]+=a[i^(1<<j)];
            }
        }
        int mx=0;
        for(int i=0; i<(1<<n); i++)
        {
            for(int j=0; j<(1<<n); j++)
            {
                if(find(p.begin(),p.end(),i^j)!=p.end())
                {
                    mx=max(mx,b[i]+b[j]);
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
