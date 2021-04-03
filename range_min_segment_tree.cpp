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

// array is 0 based index && tree is 1 based i.e. if l,r value from query is 1 based then subtrarct -1+n is in tree.
 
const int maxn = 2e5+15; 
vi tree(2*maxn);

void build(int n){
    for(int i=n-1;i>=1;i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}


int rangemin(int l, int r,int n){
    l+=n, r+=n;      // this for zero based l and r....   
    int mn = mod;
    while(l<=r){
               if(l&1) {
                   mn = min(mn, tree[l]);
                   l++;
               }
               if(!(r&1)){
                   mn = min(mn, tree[r]);
                   r--;
               }
               l>>=1;
               r>>=1;
       }
    return mn;
} 

void solve(){
	
  foo(i,n+5) v[i] = 0;
  foo(i,2*n+5) tree[i] = 0;
  foo(i,n) {
         cin>>v[i];
         tree[i+n] = v[i];
    }
    build(n);
 
} 
      
      
signed main(){
   ok
   int t;
   t = 1;
   //cin>>t;
     while(t--){
      solve();
    }
}
