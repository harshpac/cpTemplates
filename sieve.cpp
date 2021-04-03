#include<iostream>
#define lli long long int
using namespace std;
#include<vector>

vi is_p(1000005, 1);
vi primes;

void sieve(){
	is_p[0] = is_p[1]=0;
	for(int i=2;i<=1000002;i++){
		if(is_p[i]){
			for(int j=i*i;j<=1000002;j+=i)
			is_p[j]=0;
		}
	}
    for(int i = 0;i<1000005;i++){
        if(is_p[i]) {
            primes.pb(i);
        }
    }
}
vector<lli> dp(1000003);

lli go(lli n){
	if(n==0) return dp[n]=0;
	if(dp[n]) return dp[n];
	if(n==1) return dp[n]=1;
  //  if(isp[n]) return dp[n]=1;

	lli ans1 = 1+go(n-is_p[n]);
	lli ans2 = 1+go(n-1);

   return dp[n] = min(ans1,ans2);
	
}

lli main(){
	lli t; cin>>t;
	sieve();
	
	lli prev = 0;
	for(lli i=1;i<=1000001;i++){
		if(is_p[i]){
             prev=i;
		}
		else {
			is_p[i]=prev;
		}
	}

	lli res = go(1000001);

	//for(lli i=1;i<=100;i++) cout<<is_p[i]<<" ";
	while(t--){
		lli n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
}

