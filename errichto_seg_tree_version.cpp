#include<iostream>
#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define sort(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define uniq(v) sort(v); v.resize(unique(v.begin(), v.end())-v.begin());
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<int,int>>
#define mod 1000000007
               
                
int max(int a,int b){ if(a>b) return a; return b; }
int min(int a,int b){ if(a<b) return a; return b; }
int abbs(int a,int b){   if(a-b < 0) return b-a; return a-b; }
 
 
 
void solve(){
    
    int n; cin>>n;
    vi v(n);
    foo(i,n){
       cin>>v[i];
    }
    int b = 1;
    while(b<n) b*=2;
    vi tree(2*b);
    foo(i,n) tree[i+b] = v[i];
    for(int i=b-1;i>=0;i--) tree[i] = min(tree[2*i] , tree[2*i+1]);
    // for(int i=0;i<32;i++){
    //     cout<<"i "<<i<<" "<<tree[i]<<"\n";
    // }
    int q; cin>>q;
    
    while(q--){
        int sign;
        cin>>sign;
        if(sign==-1){
            // update
            int ind, val;
            cin>>ind>>val;
            ind--;
            ind+=b;
            tree[ind] = val;
            ind/=2;
            while(ind>0) {
                tree[ind] = min(tree[2*ind], tree[2*ind+1]);
                ind/=2;
            }
            continue;
        }
        int l,r; cin>>l>>r;
        l--, r--;
        l+=b, r+=b;
        int ans = mod;
         while(l<=r){
            if(l&1){
                ans = min(ans, tree[l]);
                l++;
            }
            if(!(r&1)){
                ans = min(ans, tree[r]);
                r--;
            }
            l>>=1;
            r>>=1;
         }
        cout<<ans<<"\n";
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
