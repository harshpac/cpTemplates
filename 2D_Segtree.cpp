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
 



int query(int l, int r, vi &tree, int n){
    l+=n, r+=n;
    int s = 0;
    while(l<=r){
        if(l&1) s+=tree[l], l++;
        if(!(r&1)) s+=tree[r], r--;
        l>>=1, r>>=1;
    }
    return s;
}



void update(int in, vi &tree, int val, int n){
    in+=n;
    tree[in] = val;
    while(in>1){
        in>>=1;
        tree[in] = (tree[in*2] + tree[in*2+1]);
    }
}


void fill(vi &tree, vi &dp, int n){
    
    fo(i,n){
        tree[i+n] = dp[i];
    }
    for(int i=n-1;i>=1;i--){
        tree[i] = (tree[2*i] + tree[2*i+1]);
    }

}


 
void solve(){
    
    int n,kk; cin>>n>>kk;
    kk++;
    vi v(n+5);
    foo(i,n) {
        cin>>v[i];
        --v[i];
    }
    vector<vector<int>> dp(kk+5,vector<int>(n+5,0));
    
    //  transitions ......  for j<i and v[j]<v[i]  and for all k  dp[i][k]+=dp[j][k-1]

    vector<vector<int>> tree(kk+5,vector<int>(4*n+5,0));
    foo(i,n) dp[1][i] = 1;
    //    for(int i=1;i<kk;i++){
    //        fill(tree[i], dp[i], n);
    // }

 int ans = 0;
   for(int i=0;i<n;i++){
        // dp[1][i] = 1;
          for(int k=2;k<=kk;k++){
              if(v[i]>0)
               dp[k][i] += query(0, v[i]-1, tree[k-1], n);   
          }
          for(int j=1;j<=kk;j++) update(v[i], tree[j], dp[j][i], n);
          ans+=dp[kk][i];
   }

   foo(i,n){
        fo(j,kk) cout<<dp[j][i]<<" ";
        cout<<"\n";
    }
 
  //foo(i,n) ans+=dp[kk][i];
  cout<<ans;
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