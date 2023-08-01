#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int arr[N], cxor[N];

struct trieNode{
    trieNode *child[2];
    trieNode(){
        child[0]=NULL;
        child[1]=NULL;
    }
};
void insert(trieNode *root,int n)
{
    trieNode *cur=root;
    for(int i=30;i>=0;i--)
    {
        bool f=(bool)(n&(1<<i));
        if(cur->child[f]==NULL)
        {
            cur->child[f]=new trieNode();
        }
        cur=cur->child[f];
    }
}
int search(trieNode *root,int n)
{
    trieNode *cur=root;
    int max_xor=0;
    for(int i=30;i>=0;i--)
    {
        bool f=(bool)(n&(1<<i));
        if(cur->child[!f])
        {
            max_xor|=(1<<i);
            cur=cur->child[!f];
        }
        else
        {
            cur=cur->child[f];
        }
    }
    return max_xor;
}

void solve(int casenum)
{
    trieNode *root=new trieNode();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i==1) cxor[i]=arr[i];
        else cxor[i]=cxor[i-1]^arr[i];
    }

    int ans=cxor[1];
    insert(root,cxor[1]);
    for(int i=2;i<=n;i++)
    {
        ans=max({ans,cxor[i],search(root,cxor[i])});
        insert(root,cxor[i]);
    }
    cout<<ans;
}

int main()
{

    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
}

/*

https://cses.fi/problemset/task/1655/

*/
