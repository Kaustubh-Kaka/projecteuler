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

    int n = 20000;
    vector<set<pii>> a(n + 1);

    a[1] = {{0, 0}};
    for (int i = 2; i <= n; i++) {
        vector<int> div;
        for (int j = 1; j * j <= i; j++)
            if (i % j == 0) div.push_back(j), div.push_back(i / j);
        for (int j = 1; j < div.size(); j++)
            for (auto& x : a[i / div[j]])
                a[i].insert({div[j] + x.first, x.second + 1});
    }

    vector<ll> km(2 * n, 1e6);
    for (int i = 0; i <= n; i++)
        for (auto& x : a[i])
            km[i - x.first + x.second] = min(km[i - x.first + x.second], ll(i));

    int m = 12000;
    set<int> xx;
    ll ans = 0;

    for (int i = 2; i <= m; i++) xx.insert(km[i]);
    for (auto& x : xx) ans += x;

    cout << ans << '\n';
    if (*(--xx.end()) == int(1e6)) cout << "bad\n";

    /*
    the idea is to consider the sums the divisor combinations of x can make and
    note how many divisors there are. this is done with trivial dp, the divisor
    finding part can be optimized and so can the dp probably to O(1) per insert
    instead of O(log(n)) with a linear sieve like idea but this is fast enough
    */

    return 0;
}
