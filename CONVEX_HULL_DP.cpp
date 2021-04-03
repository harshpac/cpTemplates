#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#include<vector>
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define sort(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_Hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll find(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};
 
ll n;
const ll mxn = 1e6 + 5;
ll a[mxn];
ll b[mxn];
ll c[mxn];
ll ans = 0;	

dynamic_Hull hull;
ll p[200005];
ll dp[200005];

void solve() {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	
	ll r = 0;
	for (ll i = 0; i < n; i++) {
		r += a[i];
		p[i] = r;
	}
	
	memset(dp, 0, sizeof(dp));
	hull.insert_line(0, 0);




    /*
    
    if dp[i] relate as .... dp[i] = min( f[j]*b[i] + dp[j]) for all j<i
    
      then x = b[i], m = f[j], c = dp[j]
      
    ///    insert function...........> insert a line with slope n, intercept c

    // eval function-----------------> find maximum line point for given x coordinate  
    // to find min   insert everything with neg sign, and get with negative sign


    */
	
	for (ll i = 1; i < n; i++) {
		dp[i] = p[i] * b[i] - hull.find(b[i]);    // evaluate at x = b[i]
		hull.insert_line(p[i - 1], -dp[i]);       // inserting neg sign for min.
	}
	
	for (ll i = 0; i < n; i++) cout << dp[i] << " ";
}

int main() {
    ok
	int t = 1;
   // cin>>t;
    while(t--){
       solve();
    }
} 
