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

    // freopen("./input.txt", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) {
        decltype(high_resolution_clock::now()) st, en;

        st = high_resolution_clock::now();
        auto next = [](const vector<vector<double>>& a) {
            int n = a.size();
            vector<vector<double>> na(n, vector<double>(n, 0));

            vector<pii> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            auto good = [n](int i, int j) {
                return i >= 0 && j >= 0 && i < n && j < n;
            };

            int tcnt = 0;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    tcnt = 0;
                    for (int k = 0; k < mv.size(); k++)
                        if (good(i + mv[k].first, j + mv[k].second)) tcnt++;
                    for (int k = 0; k < mv.size(); k++)
                        if (good(i + mv[k].first, j + mv[k].second))
                            na[i + mv[k].first][j + mv[k].second] +=
                                a[i][j] / double(tcnt);
                }
            return na;
        };

        auto kst = [next](vector<vector<double>>& a, int k) {
            vector<vector<double>> b = a;
            while (k--) b = next(b);
            return b;
        };

        auto hdmp = [](const vector<vector<double>>& a,
                       const vector<vector<double>>& b) {
            int n = a.size();
            vector<vector<double>> c(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) c[i][j] = a[i][j] * b[i][j];
            return c;
        };

        auto inp = [](const vector<vector<double>>& a) {
            int n = a.size();

            vector<vector<double>> b(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) b[i][j] = 1 - a[i][j];
            return b;
        };

        auto pm = [](const vector<vector<double>>& a) {
            int n = a.size();

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cout << a[i][j] << " \n"[j == n - 1];
        };

        int n = 30, k = 50;

        vector<vector<double>> init(n, vector<double>(n, 1)),
            board(n, vector<double>(n, 0)), kstep(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                board[i][j] = 1;

                init = hdmp(init, inp(kst(board, k)));

                board[i][j] = 0;
            }

        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) ans += init[i][j];
        cout << fixed << setprecision(10) << ans << '\n';

        en = high_resolution_clock::now();
        cout << duration_cast<microseconds>(en - st).count() / 1000.0
             << " ms\n";
    }
    return 0;
}