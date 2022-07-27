#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;

struct trieNode{
    bool isLast;
    trieNode *child[27];
    trieNode()
    {
        isLast = false;
        for(int i=0; i<27; i++)
        {
            child[i] = NULL;
        }
    }
};

trieNode *root;

void insert(const string &str)
{
    trieNode *curr = root;
    int len = (int)str.size();
    for(int i=0; i<len; i++)
    {
        int idx = str[i] - 'a';
        if( curr->child[idx] == NULL )
        {
            curr->child[idx] = new trieNode();
        }
        curr = curr->child[idx];
    }
    curr->isLast = true;
}

string query(const string &str)
{
    trieNode *curr = root;
    int len = (int)str.size();
    string ans;
    for(int i=0; i<len; i++)
    {
        int idx = str[i] - 'a';
        if(curr->child[idx] == NULL) return string("");
        ans.push_back(str[i]);
        curr = curr->child[idx];
        if(i == len-1 and curr->isLast) return ans;
    }

    again:
    for(char c = 'a'; c<='z'; c++)
    {
        int idx = c - 'a';
        if(curr->child[idx] != NULL)
        {
            ans.push_back(c);
            curr = curr->child[idx];
            if(curr->isLast) return ans;
            else goto again;
        }
    }
}

string queryMin()
{
    trieNode *curr = root;
    string ans;
    again:
    bool flag = false;
    for(char c = 'a'; c<='z'; c++)
    {
        int idx = c - 'a';
        if(curr->child[idx] != NULL)
        {
            ans.push_back(c);
            flag = true;
            curr = curr->child[idx];
            if(curr->isLast) return ans;
            else goto again;
        }
        if(c == 'z' and !flag) return string("");
    }
}

void solve()
{
    root = new trieNode();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int type;
        cin>>type;
        string str;
        cin>>str;
        if(type == 1)
        {
            insert(str);
        }
        else
        {
            if(str == ".")
            {
                string res = queryMin();
                if(res.size() == 0) cout<<"No word found!"<<endl;
                else cout<<res<<endl;
            }
            else
            {
                string res = query(str);
                if(res.size() == 0) cout<<"No word found!"<<endl;
                else cout<<res<<endl;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++)
    {
        solve();
    }
}

/*

https://toph.co/p/yet-another-real-life-problem

*/
