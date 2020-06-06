#include <iostream>
#include <vector>
//#include <list>
#include <queue>
//#include <unordered_map>
#include <algorithm>
//#include <string>
#include <cstring>
#include <cmath>
using namespace std;

//dijkstra algo
//https://vjudge.net/contest/373820#problem/B
//

struct compare
{
    bool operator() (const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
};

int main()
{
    //unsigned long long int i,j,k,n,t;
    int i,j,k,t;
    //unsigned long long int x,y,z;
    int x,y,z,m,mod,n;
    cin>>t;
    int parx,pary;
    int zz,xx,yy;
    int st,end;
    mod=1000000000+7;
    pair<int,int> p1,p2;
    int w,wt;
    for(k=1;k<=t;k++)
    {
        cin>>n>>m>>st>>end;
        vector<pair<int, int> > a[n];
        vector<int> dis(n,mod);
        vector<bool> vis(n,false);
        for(i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            a[x].push_back(make_pair(z,y));
            a[y].push_back(make_pair(z,x));
        }
        priority_queue<pair<int,int> , vector<pair<int,int> > , compare> q;
        q.push(make_pair(0,st));
        dis[st]=0;
        while(!q.empty())
        {
            p1=q.top();
            q.pop();
            x=p1.second;
            w=p1.first;
            if(vis[x])
                continue;
            for(i=0;i<a[x].size();i++)
            {
                p2=a[x][i];
                y=p2.second;
                wt=p2.first;
                if(vis[y]==false && dis[y]>= dis[x] + wt)
                {
                    dis[y]=dis[x]+wt;
                    q.push(make_pair(dis[y],y));
                }
            }
            vis[x]=true;
        }
        if(dis[end]==mod)
        {
            if(k!=t)
            {
                cout<<"Case #"<<k<<": unreachable"<<"\n";
                continue;
            }
            else
            {
                cout<<"Case #"<<k<<": unreachable";
                return 0;
            }
        }
        if(k!=t)
            cout<<"Case #"<<k<<": "<<dis[end]<<"\n";
        else
            cout<<"Case #"<<k<<": "<<dis[end]<<"\n";
    }
    return 0;
}