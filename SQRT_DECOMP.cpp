#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<math.h>
#define lli long long int
#include<vector>
#define vi vector<int>
#include <bits/stdc++.h>

//0 based indexing

struct query{
	int l;
	int r;
	//int i;
};

query qu[100];

int n;	


int arr[100];

int bkt[13];

int  init(){
	
	int blk=floor(sqrt(n));

	int space=(n%blk==0)?n/blk:(n/blk + 1);
	int j=0; 
	for(int i=0;i<space;i++){
		
		bkt[i]=INT_MAX;
		for(int x=0;x<blk;x++){
		bkt[i] = min(bkt[i],arr[j]);
		j++; if(j==n) break;
	}

	}

	
	for(int j=0;j<space;j++) cout<<bkt[j]<<" ";  cout<<"    "<<space;
	
	return blk;
}

int getans(int l, int r, int blk){
	int mn=INT_MAX;
        int LB=l/blk;
        int RB= r/blk;
        
        if(LB==RB){
        	for(int i=l;i<=r;i++)
        	mn=min(mn,arr[i]);
		}                                      //0 1 2   3 4 5   6 7 8   9 10
		
		else{
			for(int i=l;i<(blk*(LB+1));i++)
			mn=min(arr[i],mn);
			
			for(int i=LB+1;i<RB;i++)
			mn = min(mn,bkt[i]);
			
			for(int i=RB*blk;i<=r;i++)
			mn = min(mn, arr[i]);
		}
		
		return mn;
}

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	                                                     //running fine.......done*
int b = init();
	
	int q,l,r; cin>>q; 
	
    for(int i=0;i<q;i++){
    	cin>>l>>r;
    	int x=getans(l,r,b);
    	cout<<"......."<<"   "<<x;
	}
}

