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

    freopen("./0011data.txt", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) {
        int n = 20;
        vector<vector<int>> a(n, vector<int>(20));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        int kk = 4, ans = 0, tans = 0;

        vector<pii> mv = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

        auto gg = [n](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < n;
        };

        bool tg = false;

        for (int k = 0; k < mv.size(); k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    tg = true;
                    tans = 1;
                    for (int l = 0; l < kk; l++)
                        if (!gg(i + l * mv[k].first, j + l * mv[k].second)) {
                            tg = false;
                            break;
                        } else
                            tans *=
                                a[i + l * mv[k].first][j + l * mv[k].second];
                    if (tg) ans = max(ans, tans);
                }
        cout << ans << '\n';
    }
    return 0;
}