#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define int long long int
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define sort(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<int,int>>
#include <map>
#define mod 1000000007
               
                
int max(int a,int b){ if(a>b) return a; return b; }
int min(int a,int b){ if(a<b) return a; return b; }
int abbs(int a,int b){   if(a-b < 0) return b-a; return a-b; }
 
const int maxn = 1e5+7;
const int maxd = 20;
int n;

int lca[maxn][maxd+2];
vp adj[maxn];
vi level(maxn);

void dfs1(int node,int lvl, int par){
   level[node] = lvl;
   lca[node][0] = par;

   for(auto x: adj[node]){
       if(x.first !=par ){
           dfs1(x.first, lvl+1, node);
       }
   }
}

void init(){
   for(int i=1;i<=n;i++){
       fo(j,maxd){
           lca[i][j] = -1;
       }
   }
   dfs1(1,0,-1);
   for(int j=1;j<=maxd;j++){
       for(int i=1;i<=n;i++){
           if(lca[i][j-1]!=-1){
           int par = lca[i][j-1];
           lca[i][j] = lca[par][j-1];
           }
       }
   }
}

int findLCA(int a, int b){
    if(level[b] < level[a]) swap(a,b);
    int d = level[b]-level[a];

    while(d>0){
        int i = log2(d);
        b = lca[b][i];
        d-=1<<i;
    }
    if(a==b) return a;
    for(int i=maxd;i>=0;i--){
        if(lca[a][i]!=lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

 
void solve(){
     
   cin>>n;
    foo(i,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb({b,0});
        adj[b].pb({a,0});
    }


    init();

   int q,x,y;
   cin>>q;
   while(q--){
   int a,b; cin>>a>>b;
   int l = findLCA(a,b);
   cout<<l<<"\n";
   }

 
} 
      
      
signed main(){
   ok
   int t;
   t = 1;
  // cin>>t;
     while(t--){
      solve();
    }
}
