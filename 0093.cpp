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

    auto genset = [](const vector<double>& a) {
        set<pair<double, int>> dp, ndp;
        dp.insert({0, 0});

        int it = a.size();

        const double eps = 1e-8;

        while (it--) {
            ndp = {};
            for (auto& x : dp)
                for (int k = 0; k < a.size(); k++)
                    if (((1 << k) & x.second) == 0) {
                        ndp.insert({a[k] - x.first, x.second | (1 << k)});
                        ndp.insert({x.first - a[k], x.second | (1 << k)});
                        ndp.insert({a[k] + x.first, x.second | (1 << k)});
                        ndp.insert({a[k] * x.first, x.second | (1 << k)});
                        if (abs(x.first) > eps)
                            ndp.insert({a[k] / x.first, x.second | (1 << k)});
                        if (abs(x.first) > eps)
                            ndp.insert({x.first / a[k], x.second | (1 << k)});
                    }
            for (auto& x : ndp) dp.insert(x);
        }

        set<double> conv;
        for (auto& x : dp)
            if (x.second == ((1 << a.size()) - 1)) conv.insert(x.first);
        return conv;
    };

    const double eps = 1e-8;

    auto test = [&eps](const set<double>& a) {
        int ans = 0;
        while (a.lower_bound({ans - eps}) != a.end() &&
               abs(*a.lower_bound(ans - eps) - ans) < eps)
            ans++;
        return ans - 1;
    };

    int ans = 0, mind, temp;

    for (int i = 1; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            for (int k = j + 1; k < 10; k++)
                for (int l = k + 1; l < 10; l++) {
                    temp = test(
                        genset({double(i), double(j), double(k), double(l)}));
                    if (temp > ans) {
                        ans = temp;
                        mind = 1000 * i + 100 * j + 10 * k + l;
                    }
                }

    cout << ans << ' ' << mind << '\n';

    /*
    the idea is practically bruteforce, maintain a set with the current value
    of the expression and a bitmask of length 4 that represents which digits
    have been used, at the end combine all values with mask 1111 into a set and
    search for consecutive integers
    */

    return 0;
}
