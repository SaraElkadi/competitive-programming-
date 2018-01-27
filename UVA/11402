#include <bits/stdc++.h>

using namespace std;
const int MAX=4000000;
pair<int,int> tree[MAX];
string ss="0";
int lazy[MAX];
int from,to;
void build(int s,int e,int p)
{
    if(s==e)
    {
        if(ss[s]=='0')
        {
            tree[p].first=1;
            tree[p].second=0;
        }
        else
        {
            tree[p].second=1;
            tree[p].first=0;
        }
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p]=make_pair(tree[2*p].first+tree[2*p+1].first,tree[2*p].second+tree[2*p+1].second);
}

void updateRange(int val,int s, int e, int p)
{
    if(lazy[p])
    {
        if(lazy[p]==2)
        {
            tree[p].first=(e-s+1);
            tree[p].second=0;
        }
        else if(lazy[p]==1)
        {
            tree[p].first=0;
            tree[p].second=(e-s+1);
        }
        else if(lazy[p]==3)
        {
            int temp=tree[p].first;
            tree[p].first=tree[p].second;
            tree[p].second=temp;
        }
        if(s!=e)
        {
            if(lazy[p]!=3)
            {
                lazy[p*2] = lazy[p];
                lazy[p*2+1] = lazy[p];
            }
            else
            {
                lazy[p*2]=(3-lazy[2*p]);
                lazy[p*2+1]=(3-lazy[2*p+1]);
            }
        }
        lazy[p] = 0;
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        if(val==2)
        {
            tree[p].first=(e-s+1);
            tree[p].second=0;
        }
        else if(val==1)
        {
            tree[p].first=0;
            tree[p].second=(e-s+1);
        }
        else if(val==3)
        {
            int temp=tree[p].first;
            tree[p].first=tree[p].second;
            tree[p].second=temp;
        }
        if(s!=e)
        {
            if(val!=3)
            {
                lazy[2*p]=val;
                lazy[2*p+1]=val;
            }
            else
            {
                lazy[p*2]=(3-lazy[2*p]);
                lazy[p*2+1]=(3-lazy[p*2+1]);
            }
        }
        lazy[p]=0;
        return;
    }
    int mid = (s + e) / 2;
    updateRange(val, s, mid,2*p);
    updateRange(val, mid+1, e,2*p+1);
    tree[p].first = tree[p*2].first + tree[p*2+1].first;
    tree[p].second = tree[p*2].second + tree[p*2+1].second;
}

pair<int,int> queryRange(int s,int e,int p)
{
    if(s>e||s>to||e<from)
        return make_pair(0,0);
    if(lazy[p])
    {
        if(lazy[p]==2)
        {
            tree[p].first=(e-s+1);
            tree[p].second=0;
        }
        else if(lazy[p]==1)
        {
            tree[p].first=0;
            tree[p].second=(e-s+1);
        }
        else if(lazy[p]==3)
        {
            int temp=tree[p].first;
            tree[p].first=tree[p].second;
            tree[p].second=temp;
        }
        if(s!=e)
        {
            if(lazy[p]!=3)
            {
                lazy[p*2] = lazy[p];
                lazy[p*2+1] = lazy[p];
            }
            else
            {
                lazy[p*2]=(3-lazy[2*p]);
                lazy[p*2+1]=(3-lazy[2*p+1]);
            }
        }
        lazy[p] = 0;
    }
    if(s>=from&&e<= to)
        return tree[p];
    int mid = (s+ e) / 2;
    pair<int,int>p1 = queryRange(s, mid,p*2);
    pair<int,int> p2 = queryRange( mid + 1,e,p*2+1);
    return make_pair(p1.first+p2.first,p1.second+p2.second);
}
int main()
{
    int tt,n,k,m;
    string s;
    char c;
    cin>>tt;
    for(int t=1; t<=tt; t++)
    {

        for(int i=0;i<MAX;i++){
            lazy[i]=0;
            tree[i]=make_pair(0,0);
        }
        ss="0";
        int q=1;
        cout<<"Case "<<t<<":"<<endl;
        cin>>n;
        while(n--)
        {
            cin>>k>>s;
            for(int j=0; j<k; j++)
            {
                ss+=s;
            }
        }
        int sz=ss.size()-1;
        build(1,sz,1);
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>c>>from>>to;
            from++;
            to++;
            if(c=='F')
                updateRange(1,1,sz,1);
            else if(c=='E')
                updateRange(2,1,sz,1);
            else if(c=='I')
                updateRange(3,1,sz,1);
            else
            {
                cout<<"Q"<<q++<<": "<<queryRange(1,sz,1).second<<endl;
            }
        }
    }
    return 0;
}
