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

    auto polmult = [](const vector<ll>& a, const vector<ll>& b) {
        vector<ll> c(a.size() + b.size() - 1, 0);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];
        return c;
    };

    auto factor = [](ll n) {
        vector<pii> fac;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) n /= i, cnt++;
                fac.push_back({i, cnt});
            }
        if (n - 1) fac.push_back({n, 1});
        return fac;
    };

    auto factorpol = [&factor, &polmult](ll n) {
        vector<ll> cur = {1}, temp;
        vector<pii> fres = factor(n);

        for (int i = 0; i < fres.size(); i++) {
            temp = {};
            for (int j = 0; j <= fres[i].second; j++) temp.push_back(1);
            cur = polmult(cur, temp);
        }
        return cur;
    };

    auto pfactor = [&factor](ll n) {
        vector<pii> a = factor(n);
        for (ll i = 0; i < a.size(); i++)
            cout << '(' << a[i].first << ' ' << a[i].second << ") ";
        cout << '\n';
    };

    auto mval = [&factorpol](ll n) {
        return [](const vector<ll>& a) {
            return *max_element(all(a));
        }(factorpol(n));
    };

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

    const ll plim = 50, nlim = 1e18, slim = 1e4;
    auto plist = soe(plim);

    vector<vector<ll>> ppow(plist.size());
    for (int i = 0; i < plist.size(); i++) {
        ppow[i].push_back(plist[i]);
        while ((__int128_t)ppow[i][ppow[i].size() - 1] * plist[i] <=
               (__int128_t)nlim)
            ppow[i].push_back(ppow[i][ppow[i].size() - 1] * plist[i]);
    }

    vector<ll> nums = {1}, nnums;

    ll bval = 3;

    for (int i = 0; i < ppow.size(); i++) {
        for (int j = 0; j < ppow[i].size(); j++)
            for (int k = 0; k < nums.size(); k++)
                if ((__int128_t)nums[k] * ppow[i][j] <= (__int128_t)nlim)
                    nnums.push_back(nums[k] * ppow[i][j]);

        nums = nnums;
        sort(all(nums));
        for (auto& x : nums)
            if (mval(x) > slim) {
                if (mval(bval) > slim) {
                    if (x < bval) bval = x;
                } else
                    bval = x;
                break;
            }
        nnums = {};
    }

    cout << bval << ' ' << mval(bval) << '\n';
    pfactor(bval);

    /*
    I know there is a better way to solve this, I just can't prove it
    _cue poster boy_. there is probably something with the generating functions
    directly, probably some dp that only cares about the number of polynomials
    multiplied and I laters substitute the primes themselves, this works for now
    but come back and optimise it later.
    */

    auto linearsieve = [](int n) {
        vector<int> sieve(n + 1, 0), cnt(n + 1, 0), primes;

        for (int i = 2; i <= n; i++) {
            if (sieve[i] == 0) primes.push_back(i), sieve[i] = i, cnt[i] = 1;
            for (int j = 0; j < primes.size() && primes[j] <= sieve[i] &&
                            i * primes[j] <= n;
                 j++)
                sieve[i * primes[j]] = primes[j],
                          cnt[i * primes[j]] =
                              cnt[i] + 1 - (primes[j] == sieve[i]);
        }
        return cnt;
    };

    /*
    this sieve technically does nothing but this is what I used to 'prove' that
    I only need to look at numbers with many prime factors, the cnt array counts
    the number of primes in the factorization of n, someday I will understand
    what highly composite numbers are and how to generate them, today is not
    that day.
    */
    return 0;
}