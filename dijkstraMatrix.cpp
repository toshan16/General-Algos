    #include<bits/stdc++.h>

//https://www.spoj.com/problems/SHOP/
//Djikstra using DFS in a binary matrix
    using namespace std;
    int ro[4]={1,-1,0,0};
    int co[4]={0,0,1,-1};
    int r,c,n,m;
    int res;
     
    void dfs(vector<string> &a,vector<vector<int> > &dp,int i,int j,int t){
        if(t>res)
            return;
        if(dp[i][j]==0)
            dp[i][j]=t;
        else{
            if(t>dp[i][j]){
                return;
            }
            else
               dp[i][j]=t;
            }
        for(int ii=0;ii<4;ii++){
            r=ro[ii]+i;
            c=co[ii]+j;
            if(r<0 || c<0 || r>=n || c>=m)
                continue;
            if(a[r][c]=='X')
                continue;
            if(a[r][c]=='D'){
                res=min(res,t);
            }
            dfs(a,dp,r,c,t+(a[r][c]-'0'));
        }
        return;
    }
     
     
    int main(){
        int i,j,k,t;
        int x,y,z,pr;
        string s;
        vector<string> a;
        int fl=0;
        while(1){
            cin>>m>>n;
            if(n==0 && m==0)
                break;
            res=10000000;
            fl=0;
            for(i=0;i<n;i++){
                cin>>s;
                a.push_back(s);
            }
            vector<vector<int> > dp(n,vector<int> (m,0));
           
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    if(a[i][j]=='S'){
                        dfs(a,dp,i,j,0);
                        fl=1;
                        break;
                    }
                }
                if(fl==1)
                    break;
            }
            cout<<res<<"\n";
            a.clear();
        }
    } 