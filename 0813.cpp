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

    auto mult = [](const vector<ll>& a, const vector<ll>& b, ll M = 1e9 + 7) {
        map<ll, int> fr;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++) fr[(a[i] + b[j]) % (M - 1)] ^= 1;
        vector<ll> res;
        for (auto& x : fr)
            if (x.second) res.push_back(x.first);
        return res;
    };

    auto be = [&mult](const vector<ll>& a, ll x) {
        vector<ll> ans = {0}, m = a;
        while (x) {
            if (x & 1) ans = mult(ans, m);
            m = mult(m, m);
            x >>= 1;
        }
        return ans;
    };

    auto bell = [](ll a, ll x, ll M = 1e9 + 7) {
        ll ans = 1, m = a;
        while (x) {
            if (x & 1) ans = (ans * m) % M;
            m = (m * m) % M;
            x >>= 1;
        }
        return ans;
    };

    auto rep = [&bell](const vector<ll>& a, ll M = 1e9 + 7) {
        ll ans = 0;
        for (ll i = 0; i < a.size(); i++) ans = (ans + bell(2, a[i], M)) % M;
        return ans;
    };

    auto torep = [](ll x) {
        vector<ll> ans;
        int it = 0;
        while (x) {
            if (x & 1) ans.push_back(it);
            x >>= 1;
            it++;
        }
        return ans;
    };

    /*
    I am very proud of the fact that I managed to compress the whole calculation
    into one line of nonsense
    */
    cout << rep(be(be(torep(11), (1ll << 36)), bell(12, 8, ll(1e17)))) << '\n';

    /*
    the key idea is to store numbers as lists of which powers of two they
    contain, the xor product of these lists can then be calculated and hence the
    answer
    */

    return 0;
}
