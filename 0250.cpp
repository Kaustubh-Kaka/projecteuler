#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef __int128_t ll;
typedef long double ld;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll binexp(ll a, ll x, ll M) {
    ll mult = a, ans = 1;
    for (ll ind = 0; (1ll << ind) <= x; ind++) {
        if ((1ll << ind) & x) ans = (ans * mult) % M;
        mult = (mult * mult) % M;
    }
    return ans;
}

vector<ll> polymult(vector<ll> a, vector<ll> b, ll M) {
    vector<ll> c(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[(i + j) % (int(a.size()))] =
                (c[(i + j) % (int(a.size()))] + (a[i] * b[j]) % M) % M;
    return c;
}

vector<ll> polybinexp(vector<ll> a, ll x, ll M) {
    vector<ll> ans(a.size()), mult = a;
    ans[0] = 1;
    for (ll ind = 1; ind <= x; ind <<= 1) {
        if (ind & x) ans = polymult(ans, mult, M);
        mult = polymult(mult, mult, M);
    }
    return ans;
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    const ll M = 100000000L * 100000000L;

    int n = 250;
    vector<ll> rs(n);
    vector<ll> t(n), ans(n);
    ans[0] = t[0] = 1;

    for (ll i = 1; i <= 250250; i++) rs[binexp(i, i, 250)]++;

    for (int i = 0; i < n; i++) {
        t[i]++;
        ans = polymult(ans, polybinexp(t, rs[i], M), M);
        t[i]--;
    }

    cout << (long long)(ans[0] - 1) << '\n';

    return 0;
}
