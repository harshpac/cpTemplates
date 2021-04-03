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



// or use these
/*

int query(int l, int r, vi &tree, int n){
    l+=n, r+=n;
    int mn = mod;
    while(l<=r){
        if(l&1) mn = min(mn, tree[l]), l++;
        if(!(r&1)) mn = min(mn, tree[r]), r--;
        l>>=1, r>>=1;
    }
    return mn;
}

void update(int in, vi &tree, int val, int n){
    in+=n;
    tree[in] = val;
    while(in>1){
        in>>=1;
        tree[in] = min(tree[in*2], tree[in*2+1]);
    }
}




void fill(vi &tree, vi &dp, vi &pre, int n){
    
    fo(i,n-1){
        tree[i+n] = dp[i]+pre[i-1];
    }
    for(int i=n-1;i>=1;i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }

}

*/
 
 
 
void solve(){
     
    int n; cin>>n;
    vi v(n+5);
    foo(i,n) cin>>v[i];
    vp intr(n+5);
    fo(i,n-1) {
        cin>>intr[i].first>>intr[i].second;
        intr[i].first--, intr[i].second--;
    }
    vi pre(n+1);
    int x = 0;
    foo(i,n) x+=v[i], pre[i] = x;

    vi dp(n+5, 0);
    int sz = 4*n;
   // while(sz<n) sz*=2;
    vi tree(sz+5);
    
    // can use fill() ........by passing the arrays by which tree is to be initialised
    
    
    fo(i,n-1){
        tree[i+n] = dp[i]+pre[i-1];
    }

    for(int i=n-1;i>=1;i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }


    for(int i=1;i<n;i++){
        int l = intr[i].first, r = intr[i].second;
        
        // can use query(l, r....)
        int mn = mod;
        l+=n, r+=n;
        while(l<=r){
            if(l&1) mn = min(mn, tree[l]), l++;
            if(!(r&1)) mn = min(mn,tree[r]), r--;
            l>>=1, r>>=1;
        }
        
        // can use updatr(.....) 
        dp[i] = mn+pre[i];
        int in = i;
        in+=n;
        tree[in] = dp[i]-pre[i-1];
        while(in>1){
            in>>=1;
            tree[in] = min(tree[2*in], tree[2*in+1]);
        }
    }


    foo(i,n) cout<<dp[i]<<" ";

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
