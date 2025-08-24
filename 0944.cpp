#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

constexpr ll M = 1234567891;

ll binexp(ll a, ll x) {
    ll ind = 1, ans = 1, mult = a;
    while (ind <= x) {
        if (ind & x) ans = (ans * mult) % M;
        mult = (mult * mult) % M;
        ind <<= 1;
    }
    return ans;
}

inline ll f(ll x) { return x % M; }

inline ll fs(ll x) {
    x %= M;
    return (x * (x + 1) / 2) % M;
}

inline ll g(ll n, ll x) { return binexp(2, n - x); }

inline ll gs(ll n, ll x) {
    return ((binexp(2, n) - binexp(2, n - x)) % M + M) % M;
}

ll compute(ll l1, ll l2, ll n, ll lim) {
    ll tans = 0;
    for (int i = l1; i <= l2; i++) {
        tans = (tans + f(i) * gs(n, n / i)) % M;
        tans = (tans + g(n, i) * fs(n / i)) % M;
    }
    return tans;
}

int main() {
    fast();

    decltype(high_resolution_clock::now()) st, en;

    st = high_resolution_clock::now();

    ll n = 1e14;
    ll lim = floor(sqrt(n));

    ll ans = 0;

    ans += compute(1, lim, n, lim);

    ans = (ans - gs(n, lim) * fs(lim)) % M;
    ans = (ans - g(n, 1) * fs(n)) % M;
    ans = (ans + M) % M;

    cout << ans << '\n';

    en = high_resolution_clock::now();
    cout << duration_cast<microseconds>(en - st).count() / 1000.0 << " ms\n";

    return 0;
}

// slow without -Ofast -march=native
// with compiler flags runs in 9.476s
