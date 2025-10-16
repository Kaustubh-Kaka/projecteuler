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

    // helpers

    auto soe = [](int n) {
        vector<bool> a(n + 1, true);
        for (int i = 2; i * i <= n; i++)
            if (a[i])
                for (int j = i; i * j <= n; j++) a[i * j] = false;
        vector<ll> primes;
        for (int i = 2; i <= n; i++)
            if (a[i]) primes.push_back(i);
        return primes;
    };

    auto fac = [](int n) {
        vector<pii> ans;
        int cnt;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                cnt = 0;
                while (n % i == 0) n /= i, cnt++;
                ans.push_back({i, cnt});
            }
        if (n - 1) ans.push_back({n, 1});
        return ans;
    };

    auto pp = [](ll a, ll x, ll M) {
        ll ans = 1, m = a;
        while (x) {
            if (x & 1) ans = (ans * m) % M;
            m = (m * m) % M;
            x >>= 1;
        }
        return ans;
    };

    // logic

    int n = 20000;
    auto primes = soe(n);

    const ll M = 1e9 + 7;

    auto val = [&primes, &pp, &M](const vector<ll> &a) {
        ll res = 1;

        for (int i = 0; i < primes.size(); i++) {
            res = (res * (pp(primes[i], a[i] + 1, M) - 1)) % M;
            res = (res * pp(primes[i] - 1, M - 2, M)) % M;
        }
        return res;
    };

    ll ans = 0;

    vector<ll> cum(primes.size(), 0), cur(primes.size(), 0);
    vector<pii> temp;
    for (int i = 1; i <= n; i++) {
        temp = fac(i);
        for (auto &x : temp)
            cur[lower_bound(all(primes), x.first) - primes.begin()] += x.second;

        for (int j = 0; j < primes.size(); j++) cum[j] += (i - 1) * cur[j];

        ans = (ans + val(cum)) % M;

        for (int j = 0; j < primes.size(); j++) cum[j] -= (i + 1) * cur[j];
    }

    cout << ans << '\n';

    /*
    the reasoning is to store the products of the coefficients as lists of
    their prime factoriations with some precalculation, it's not pretty but
    it works
    */

    return 0;
}
