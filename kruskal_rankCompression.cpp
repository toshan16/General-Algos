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

//kruskal algo with rank compression. worst case reduced from O(V), O(log(V))
//Refer https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
//return total summation of weights - MST weight
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2678
//https://vjudge.net/contest/320916#problem/A
//////WIHTOUT RANK COMPRESSION

struct edge
{
    int u;
    int v;
    int wt;
};

struct subset
{
    int par;
    int rank;
};

bool compare(edge &e1, edge&e2)
{
    return e1.wt < e2.wt;
}

int getparent(vector<subset> &sub, int x)
{
    if(sub[x].par==-1)
    {
        return x;
    }
    return getparent(sub, sub[x].par);
}

bool check(vector<subset> &sub, int x, int y)
{
    int parx=getparent(sub, x);
    int pary=getparent(sub, y);
    if(parx == pary)
    {
        return 0;
    }

    if(sub[parx].rank > sub[pary].rank)
    {
        sub[pary].par=parx;
    }
    else if(sub[parx].rank==sub[pary].rank)
    {
        sub[pary].par=parx;
        sub[pary].rank++;
    }
    else
    {
        sub[parx].par=pary;
    }

    return 1;
}

int main()
{
    int n,m;
    int x,y,z,a,b,i,j,k;
    int total;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        vector<subset> sub(n);
        for(int i=0;i<n;i++)
        {
            sub[i].par=-1;
            sub[i].rank=0;
        }
        vector<edge> gr;
        edge e;
        total=0;
        for(i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            e.u=x;
            e.v=y;
            e.wt=z;
            total+=z;
            gr.push_back(e);
        }
        sort(gr.begin(),gr.end(),compare);
        k=0;
        j=0;
        for(i=0;i<gr.size();i++)
        {
            a=gr[i].u;
            b=gr[i].v;
            if(check(sub,a,b))              //no cycle formed
            {
                k+=gr[i].wt;
                j++;
            }
            if(j==n-1)
            {
                break;
            }
        }
        cout<<total-k<<"\n";
    }
    return 0;
}

/*struct edge
{
	int u;
	int v;
	int wt;
};


bool compare(edge &e1, edge&e2)
{
	return e1.wt < e2.wt;
}

int getparent(vector<int> &par, int x)
{
	if(par[x]==-1)
	{
		return x;
	}
	return getparent(par, par[x]);
}

bool check(vector<int> &par, int x,int y)
{
	int parx=getparent(par,x);
	int pary=getparent(par,y);
	if(parx==pary)
	{
		return 0;
	}
	par[parx]=pary;
	return 1;
}

int main()
{
	int n,m;
	int x,y,z,a,b,i,j,k;
	int total;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		vector<int> par(n,-1);
		vector<edge> gr;
		edge e;
		total=0;
		for(i=0;i<m;i++)
		{
			cin>>x>>y>>z;
			e.u=x;
			e.v=y;
			e.wt=z;
			total+=z;
			gr.push_back(e);
		}
		sort(gr.begin(),gr.end(),compare);
		k=0;
		j=0;
		for(i=0;i<gr.size();i++)
		{
			a=gr[i].u;
			b=gr[i].v;
			if(check(par,a,b))				//no cycle formed
			{
				k+=gr[i].wt;
				cout<<a<<" "<<b<<"\n";
				j++;
			}
			if(j==n-1)
			{
				break;
			}
		}
		cout<<total-k<<"\n";
	}
	return 0;
}*/

