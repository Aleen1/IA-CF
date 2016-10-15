#include<bits/stdc++.h>
using namespace std;
ifstream f("brazi.in");
ofstream g("brazi.out");

int T,n,v[12][2],father[20];
map<string, int> mp;
string s;

void dfs(int root)
{
    if(v[root][0])
    {
        s.push_back('0');
        dfs(v[root][0]);
    }
    if(v[root][1])
    {
        s.push_back('1');
        dfs(v[root][1]);
    }
    s.push_back('2');
}

inline int find_root(int x)
{
    while(father[x]!=0) x=father[x];
    return x;
}

int main()
{
    f>>T;
    while(T--)
    {
        f>>n;
        memset(v, 0, sizeof(v));
        memset(father, 0,sizeof(father));
        s.clear();

        for(int i=1;i<n;++i)
        {
            int x,y,d;
            f>>x>>y>>d;
            v[x][d]=y;
            father[y]=x;
        }

        int root=find_root(1);
        dfs(root);

        g<<mp[s]<<'\n';
        mp[s]++;
    }

    return 0;
}
