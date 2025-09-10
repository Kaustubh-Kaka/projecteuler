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

    // cin >> t;

    int n = 1001;

    vector<vector<int>> a(n, vector<int>(n));

    vector<pii> mv = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    reverse(all(mv));
    auto good = [&a, n](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n && a[i][j] == 0;
    };

    int si = 0, sj = n - 1, sii = 0, cv = n * n;
    while (cv) {
        a[si][sj] = cv;
        if (good(si + mv[sii].first, sj + mv[sii].second))
            si += mv[sii].first, sj += mv[sii].second;
        else
            sii = (sii + 1) % mv.size(), si += mv[sii].first,
            sj += mv[sii].second;
        cv--;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i][i], ans += a[i][n - i - 1];
    --ans;
    cout << ans << '\n';

    return 0;
}