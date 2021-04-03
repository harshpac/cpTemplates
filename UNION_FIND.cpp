#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define rep(i,n) for(int i=1;i<=n;i++)
#define ff first
#define ss second
#define pb pushback
#define vii vector<lli>
using namespace std;

vi par(100002);

int min(int a , int b){
  if(a>b)
   return b;
   return a;
}

vi par;
vi size;

int find(int a){
  if(par[a]==a) return a;
  else return par[a] = find(par[a]);   
}

void uni(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x==y) return;
  if(size[x]<size[y]){
      swap(size[x], size[y]);
  }
  size[y]+=size[x];
  par[x] = y;
 }
 
 
 
int main(){
  
  int n,m;
  cin>>n>>m;
  rep(i,n) par[i] = -i;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    uni(a,b);
  }
  
 rep(i,n)
  cout<<"parent of "<<i<<"-->   "<<par[i]<<endl;
  
  int q; cin>>q;
  while(q--){
    int x,y; cin>>x>>y;
    int m = find(x);
    int n = find(y);
    
    if(m==n){
       cout<<"TIE"<<endl; continue;}
    if(par[m] < par[n])
    cout<<x<<endl;
    else cout<<y<<endl;;
  }
} 
  
  




















