#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<lli>
#define lli long long int
#define fo(i,n) for(lli i=1;i<=n;i++)
#define foo(i,n) for(lli i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define vii vector<lli>
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>
#define mod 1000000007
               
                
int max(int a,int b){
  if(a>b) return a;
  return b;
}
 
 
int min(int a,int b){
  if(a<b) return a;
  return b;
}

vi zAlgo(string &s, int n){
    vi vc(n,0);

    vc[0] = 0;
    int l=0,r=0;
    for(int i=1;i<n;i++){
         
         if(i>r){
             l = i;
             r = i;
             while(r<n && s[r]==s[r-i]) r++;
             r--;
             vc[i] = r-l+1;
         }

         else {
             int j = i-l;

             if(vc[j] < r-i+1){
                 s[i] = s[j];
             }
             else {
                 l = i;
                 while(s[r]==s[r-l] && r<n) r++;
                 r--;
                 vc[i] = r-l+1;
             }
         }
      
    }
    return vc;
}
 
  
signed main(){
    string pat,str;
    cin>>pat>>str;
    string n = pat+'$'+str;

    vi z = zAlgo(n,n.length());
    for(int x: z) cout<<x<<" ";
}