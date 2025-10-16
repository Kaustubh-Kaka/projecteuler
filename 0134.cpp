#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// #pragma GCC target("avx2")

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fast();

    auto binexp = [](ll a, ll x, ll M) {
        ll ans = 1, m = a;
        while (x) {
            if (x & 1) ans = (ans * m) % M;
            m = (m * m) % M;
            x >>= 1;
        }
        return ans;
    };

    auto soe = [](int n) {
        vector<bool> a(n + 1, true);
        for (int i = 2; i * i <= n; i++)
            if (a[i])
                for (int j = i; i * j <= n; j++) a[i * j] = false;
        vector<int> primes;
        for (int i = 2; i <= n; i++)
            if (a[i]) primes.push_back(i);
        return primes;
    };

    auto fl = [&binexp](ll p1, ll p2) {
        auto d = [](ll n) {
            ll ans = 0;
            while (n) n /= 10, ans++;
            return ans;
        };

        return (((p2 - p1) * binexp(10, p2 - 1 - d(p1), p2)) % p2) *
                   binexp(10, d(p1), ll(1e18)) +
               p1;
    };

    int n = 1e6, padding = 1e3;
    vector<int> primes = soe(n + padding);
    while (primes[primes.size() - 2] > n) primes.pop_back();

    ll ans = 0;

    for (int i = 2; i < primes.size() - 1; i++)
        ans += fl(primes[i], primes[i + 1]);
    cout << ans << '\n';

    /*
    the smallest number that satisfies the two conditions can be found using
    some modular arithmetic, the rest all implementation, I'm pretty sure this
    is the asymptotically fastest solution.
    */

    return 0;
}
