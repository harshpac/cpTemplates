#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#include<math.h>


int n;

int tree[800];
int ar[800];

void buildT(int si, int ss, int se){
	
	if(ss==se)
	{
	tree[si]=ar[ss]; return;
	}
	
	int mid=(ss+se)/2;
	
	buildT(2*si, ss, mid);
	buildT(2*si + 1, mid+1, se);
	
	tree[si]=(tree[2*si]*tree[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
	
	
	cout<<"si ss se qs qe "<<si<<" "<<ss<<" "<<se<<" "<<qs<<" "<<qe<<endl;
	
	if(se<qs || ss>qe) return 1;
	
	if(ss>=qs && se<=qe) return tree[si];
	
	int mid= (ss + se)/2;
	
	return (query(2*si, ss, mid, qs, qe) * query(2*si +1, mid+1, se, qs , qe));
	
}

int main(){
	
	int l,r; cin>>n;

	
for(int i=1;i<=n;i++) cin>>ar[i];
    
    buildT(1,1,n);
	int Q; cin>>Q;
	while(Q--){
		cin>>l>>r;
	  int x =	query(1,1,n,l,r);
	  cout<<x<<" ";
	}
	
//	for(int j=1;j<=n;j++) cout<<tree[j]<<" ";
	
}
