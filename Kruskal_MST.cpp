//UNION-FIND and Kruskal non compiling code
//ibit https://www.interviewbit.com/problems/commutable-islands/
//
//

bool compare(vector<int> a1, vector<int> a2)        //to sort edges on weight value low->high
                                                    //a1, a2 are node1, node2, weight
{
    return a1[2]<a2[2];
}

int getparent(vector<int> &parent, int x)
{
    if(parent[x]==-1)
    {
        return x;            
    }
    return getparent(parent, parent[x]);
}



bool check(vector<int> &parent, int i, int j)
{
    int px = getparent(parent, i);
    int py = getparent(parent, j);
    
    if(px==py)
    {
        return 0;
    }
    parent[px] = py;
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {       //B[i] is node1, node2, weight
    int i,j,k;
    
    /*vector<pair<int,int> > a[A+1];
    
    for(i=0;i<B.size();i++)
    {
        a[B[i][0]].push_back(make_pair(B[i][1],B[i][2]));
    }*/
    
    sort(B.begin(),B.end(),compare);
    //cout<<B.size()<<"\n";
    /*for(i=0;i<B.size();i++)
    {
        cout<<B[i][0]<<" "<<B[i][1]<<" "<<B[i][2];
        cout<<"\n";
    }*/
    i=0;
    vector<int> parent(A+1,-1);
    int res=0;
    int c=0;
    i=0;
    while(c<A-1 && i<B.size())
    {
        if(check(parent, B[i][0], B[i][1]))
        {
            res += B[i][2];
            c++;
        }
        i++;
    }
    return res;
    
}
