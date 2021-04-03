#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define int long long int
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
 

//   s e t u p s e t p r e s e t
//   a a b a a b a b a
//   0 1 0 1 2 3 4 0 1           // for each index , largest suffix nding at that index which is also a prefix
int mx,k;

vi kmp(string &ss)
{   
    vi pf(ss.length());
    int i,j=0;
    pf[0]=0;
    for(i=1;i<ss.size();i++)
    {
        while(j && ss[i]!=ss[j])
        	j=pf[j-1];
        if(ss[i]==ss[j])
        	j++;
        pf[i]=j;
       // part of question... not for all if(i<=k) mx=max(mx,pf[i]);
    }
    return pf;
}
 
void solve(){
 // 
     string s;
     mx = 0;
     cin>>s>>k;
      k--;
     // a b a b a 
     int n = s.length();
     vi v = kmp(s);
    //  if(v[n-1]==0) {
    //      cout<<"Puchi is a cheat!\n";
    //      return;
    //  }

    foo(i,n) cout<<v[i]<<" ";
    cout<<"\n";

     int val = v[n-1];
     while(val>mx && val) val = v[val-1];
     if(val==0) {
         cout<<"Puchi is a cheat!\n";
         return;
     }
     else {
         foo(i,val) cout<<s[i];
         cout<<"\n";
     }


} 
      
      
signed main(){
   ok
   int t;
   t = 1;
   cin>>t;
     while(t--){
      solve();
    }
}
