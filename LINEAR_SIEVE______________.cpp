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
const int huge = 1e17;
               
                
int max(int a,int b){ if(a>b) return a; return b; }
int min(int a,int b){ if(a<b) return a; return b; }
int abbs(int a,int b){   if(a-b < 0) return b-a; return a-b; }


const int N = 2e6+7;
int lp[N+5];
vector<int> pr;
vi sums(N+5);

vi dd(N+5);
//vi isp(N);


void sieve(){
for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }

for(int i=2;i<=N; i++){
    int x = i;
    int s = 0;
    while(x!=1){
        int p = lp[x];
        s+=p;
        while(x%p==0) x/=p;
    }
    //cout<<"s "<<s<<"\n";
    sums[i] = s;
 }    
} 
 
void solve(){
    int n; cin>>n; 
    vi v(n); foo(i,n) cin>>v[i];
    int c = 0;
    foo(i,n){
        foo(j,n){
            if(i!=j){
                if(v[j]%v[i]==0 && sums[v[j]]%sums[v[i]]==0) c++;
            }
        }
    }
    cout<<c<<"\n";
} 
      
      
signed main(){
   ok
   int t;
   t = 1;
   sieve();
   cin>>t;
     while(t--){
      solve();
    }
}
