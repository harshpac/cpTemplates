#include <bits/stdc++.h>
#define int long long
using namespace std;
#define vi vector<int>

const int p = 1e9+7;     // mod
const int N = 1000001;     // maxlimit
 
vi factorialNumInverse(N+1);
vi naturalNumInverse(N+1);
vi fact(N+1);
 
 void precompute()
{   
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
        factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
     fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
int Binomial(int N, int R)
{    
    if(N==R) return 1;
    if(N<0 || R<0 || R>N) return 0;
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    int ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
 
// Driver Code
signed main()
{
   precompute();

   int t=10;
   while(t--){
       int a,b; cin>>a>>b;
       cout<<Binomial(a,b)<<"\n";
   }
 
    return 0;

