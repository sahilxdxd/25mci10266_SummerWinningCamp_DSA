#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;
const int N = 200005;

vector<ll> fact(N);

ll expo(ll a, ll b){
    ll res = 1;

    while(b){
        if(b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll modInv(ll x){
    return expo(x, MOD - 2);
}

ll nCr(int n, int r){

    if(r < 0 || r > n)
        return 0;

    return (((fact[n] * modInv(fact[r])) % MOD)
            * modInv(fact[n-r])) % MOD;
}

void solve(){

    int n, k;
    cin >> n >> k;

    int ones = 0, x;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(x) ones++;
    }

    int zeroes = n - ones;

    ll ans = 0;

    for(int i = k/2 + 1; i <= k; i++){

        ans = (ans +
              (nCr(ones, i) * nCr(zeroes, k-i)) % MOD)
              % MOD;
    }

    cout << ans << "\n";
}

int main(){

    fact[0] = 1;

    for(int i = 1; i < N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}