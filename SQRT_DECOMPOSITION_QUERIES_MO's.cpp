#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<math.h>
#define lli long long int
#include<vector>
#define vi vector<int>
#include <bits/stdc++.h>

// 1 based indexing

// Mo's algo

int blk=170;


int arr[30003];    
int ans[200003];   int freq[1000006];



struct query{
	int l;
	int r;
	int i;
};

query qu[200003];

bool comp(query a, query b){
	
	int x=a.l/blk;
	int y=b.l/blk;
	if( x!=y)
	return (x<y);
	
    return a.r<b.r;
	
	

}

void add(int ind, int *count){
	
	freq[arr[ind]]++;
	if(freq[arr[ind]]==1)
	*count=*count + 1;
}

void remove(int ind,int *count){
	freq[arr[ind]]--;
	if(freq[arr[ind]]==0)
	*count= *count - 1;
}
                                                            // working fine.......glad...................   :))))
int main(){
    int n; cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int q,L,R; cin>>q;
	
	for(int i=1;i<=q;i++){
		cin>>L>>R;
	    qu[i].l=L--;
	    qu[i].r=R--;
	    qu[i].i=i;   
	}
	
	sort(qu, qu+q, comp);
	
	int ml=0;   int mr=-1;
	
	int c=0;

	
	for(int i=1; i<=q;i++){
		
		int l=qu[i].l; l--;
		int r=qu[i].r; r--;
		int index=qu[i].i;
		
	
		
		while(ml>l){
		
		ml--; add(ml,&c);}
		
		while(mr<r){
		mr++; add(mr,&c);}
		
			while(ml<l){
	 remove(ml,&c);	ml++;}
		
		while(mr>r) {
	 remove(mr,&c);	mr--;}
		
		ans[index]=c;
		
	}
	
	for(int i=1;i<=q;i++) cout<<ans[i]<<" ";
	
}

