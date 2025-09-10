#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

    int n = 1e6;
    set<ll> t, p, h;
    for (ll i = 1; i <= n; i++)
        t.insert(i * (i + 1) / 2), p.insert(i * (3 * i - 1) / 2),
            h.insert(i * (2 * i - 1));

    int cnt = 0;

    for (auto& x : t)
        if (p.find(x) != p.end() && h.find(x) != h.end()) {
            cout << x << '\n';
            ++cnt;
            if (cnt == 3) break;
        }

    return 0;
}