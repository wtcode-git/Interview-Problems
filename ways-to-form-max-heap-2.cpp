#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100001
vector <int> lvals(2, 0);
vector <int> fact(MAX);
vector <int> ifact(MAX);
vector <int> dp(MAX, -1);

inline void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// O(1)
inline int mul(int a, int b) { return (int)((a * 1LL * b) % MOD); }

// O(log(MOD))
int modmulinv(int n) {
    int p= MOD - 2;
    int res = 1;
    while(p) {
        if(p & 1)
            res = mul(res, n);
        n = mul(n, n);
        p >>= 1;
    }
    return res;
}

// O(1)
inline ncr(int n, int r) { return (r < 0) ? 0 : ((r > n) ? 0 : mul(fact[n], mul(ifact[r], ifact[n - r]))); }

void init(){
    int n = 2;
    int s = 2;
    // building lvals O(MAX)
    while(n < MAX){
        int c = lvals.back();
        for(int i = 0; i < s / 2; i++)
            lvals.push_back(++c);
        for(int i = 0; i < s / 2; i++)
            lvals.push_back(c);
        n += s;
    }
    // building factorials and inverse factorials O(MAX)
    fact[0]=1;
    for(int i = 1; i < MAX; i++)
        fact[i] = mul(fact[i - 1], i);
    ifact[MAX - 1] = modmulinv(fact.back());
    for(int i = MAX - 2; i >= 0; i--)
        ifact[i] = mul(ifact[i + 1], i + 1);
    // building ans for all heap sizes O(MAX)
    dp[0] = dp[1] = dp[2] = 1;
    for(int i = 3; i < MAX; i++)
        dp[i] = mul(ncr(i-1, lvals[i]), mul(dp[lvals[i]], dp[i - 1 - lvals[i]]));
    dp[0] = 0;
}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main(){
    fastIO();
    init();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}