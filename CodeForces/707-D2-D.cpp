#include <bits/stdc++.h>

using namespace std;
const int N=(1<<20);
struct node;
node* emp;
struct node
{
    int sum,lazy;
    node *l,*r;
    node()
    {
        l=r=this;
        sum=0;
        lazy=0;
    }
    node(int ss,node* lf=emp,node* rt=emp,int lz=0)
    {
        l=lf;
        r=rt;
        sum=ss;
        lazy=lz;
    }
};
node* build(int s,int e)
{
    if(s==e)
        return new node(0);
    int mid=s+((e-s)>>1);
    node* l=build(s,mid);
    node* r=build(mid+1,e);
    return new node(l->sum+r->sum,l,r);
}
node* update(node* cur,int s,int e,int n,int val)
{
    if(cur->lazy)
    {
        cur->sum=(e-s+1)-cur->sum;
        if(s!=e)
        {
            cur->l=new node(cur->l->sum,cur->l->l,cur->l->r,cur->l->lazy ^1);
            cur->r=new node(cur->r->sum,cur->r->l,cur->r->r,cur->r->lazy ^1);
        }
        cur->lazy=0;
    }
    if(n<s||n>e)
        return cur;
    if(s==e)
        return new node(val);
    int mid=s+((e-s)>>1);
    node* l=update(cur->l,s,mid,n,val);
    node* r=update(cur->r,mid+1,e,n,val);
    return new node(l->sum+r->sum,l,r);
}
node* updateRange(node* cur,int s,int e,int x,int y)
{
    if(cur->lazy)
    {
        cur->sum=(e-s+1)-cur->sum;
        if(s!=e)
        {
            cur->l=new node(cur->l->sum,cur->l->l,cur->l->r,cur->l->lazy^1);
            cur->r=new node(cur->r->sum,cur->r->l,cur->r->r,cur->r->lazy^1);
        }
        cur->lazy=0;
    }
    if(s>y||e<x)
        return cur;
    if(s>=x&&e<=y)
    {
        node* n=new node(cur->sum,cur->l,cur->r);
        n->lazy ^=1;
        if(n->lazy)
        {
            n->sum=(e-s+1)-n->sum;
            if(s!=e)
            {
                n->l=new node(n->l->sum,n->l->l,n->l->r,n->l->lazy^1);
                n->r=new node(n->r->sum,n->r->l,n->r->r,n->r->lazy^1);
            }
            n->lazy=0;
        }
        return n;
    }
    int mid=s+((e-s)>>1);
    node* l=updateRange(cur->l,s,mid,x,y);
    node* r=updateRange(cur->r,mid+1,e,x,y);
    return new node(l->sum+r->sum,l,r);
}
node* nd[100005];
int main()
{
    int n,m,q,t,a,b;
    cin>>n>>m>>q;
    emp=new node;
    nd[0]=build(1,N);
    for(int i=1; i<=q; i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>b;
            nd[i]=update(nd[i-1],1,N,(a-1)*m+b,1);
            cout<<nd[i]->sum<<endl;
        }
        else if(t==2)
        {
            cin>>a>>b;
            nd[i]=update(nd[i-1],1,N,(a-1)*m+b,0);
            cout<<nd[i]->sum<<endl;
        }
        else if(t==3)
        {
            cin>>a;
            nd[i]=updateRange(nd[i-1],1,N,(a-1)*m+1,a*m);
            cout<<nd[i]->sum<<endl;
        }
        else
        {
            cin>>a;
            nd[i]=nd[a];
            cout<<nd[i]->sum<<endl;
        }
    }
    return 0;
}
