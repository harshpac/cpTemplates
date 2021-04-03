#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define int long long int
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<int,int>>
#include <map>
#define mod 1000000007
               
                
int max(int a,int b){ if(a>b) return a; return b; }
int min(int a,int b){ if(a<b) return a; return b; }
int abbs(int a,int b){   if(a-b < 0) return b-a; return a-b; }


// In this, keep two heaps, one will have elements below the bound while one will have elements of upper bound
// take the input , if input value is less than the lower heap, or any heaps size is empty insert in it
// and then rebalance, means the diff in sizes of heaps must be less than equal to 1
// for more info, search youtube video , hackerrank running median

priority_queue<int> small;                                  // max heap  
priority_queue<int, vector<int> , greater<int>> bigger;     // min heap

void add(int val){
    if(small.size()==0 || val<small.top()) small.push(val);
    else bigger.push(val);
}

void rebalance(){
   int l = small.size();
   int r = bigger.size();
   if(l-r >= 2){
    bigger.push(small.top());
    small.pop();
   }

   if(r-l >= 2){
    small.push(bigger.top());
    bigger.pop();
   }
}

float get(){
    
    if(small.size()==bigger.size()){
        float ans = (float)(small.top()+bigger.top())/2;
      //  cout<<"ans "<<ans<<"\n";
        return ans;
    }
    else {
       return (float)small.size()>bigger.size()?small.top():bigger.top();
    }
}
 
void solve(){
   int n;
   cin>>n;
   vi v(n);
   foo(i,n) cin>>v[i];
   vector<float> median(n);
   foo(i,n){
    int val = v[i];
    add(val);
    rebalance();
  //  cout<<small.size()<<" "<<bigger.size()<<"\n";
    median[i] = get();           
    }
   foo(i,n) cout<<median[i]<<" ";   
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

