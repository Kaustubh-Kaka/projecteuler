#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dsum(ll x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    fast();

    constexpr int n = 10, iter = 20;

    // ## OLD O(d^3) implementation

    // vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(n,
    // 0))),
    //     dpc(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
    // for (int i = 100; i < 1000; i++)
    //     if (dsum(i) < 10 && dsum(i % 100) < 10)
    //         dp[dsum(i)][dsum(i % 100)][i % 10]++;

    // for (int l = 0; l < iter - 3; l++) {
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             for (int k = 0; k < n; k++) dpc[i][j][k] = 0;
    //     for (int m = 0; m < 10; m++) {
    //         for (int i = 0; i < n; i++)
    //             for (int j = 0; j < n; j++)
    //                 for (int k = 0; k < n; k++)
    //                     if (j + m < 10 && k + m < 10)
    //                         dpc[j + m][k + m][m] += dp[i][j][k];
    //     }
    //     dp = dpc;
    // }

    // ll ans = 0;
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         for (int k = 0; k < n; k++) ans += dp[i][j][k];
    // cout << ans << '\n';

    // ## NEW O(d^2) implementation

    auto start = high_resolution_clock::now();

    vector<vector<ll>> dp(n, vector<ll>(n, 0)), dpc = dp;
    for (int i = 100; i < 1000; i++)
        if (dsum(i) < 10) dp[dsum(i % 100)][i % 10]++;

    for (int l = 0; l < iter - 3; l++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) dpc[i][j] = 0;
        for (int m = 0; m < 10; m++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dp[i][j] && i + m < 10 & j + m < 10)
                        dpc[j + m][m] += dp[i][j];
        dp = dpc;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ans += dp[i][j];
    cout << ans << '\n';

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);
    cout << dur.count() << "us\n";

    return 0;
}

// optimise dp from O(d^3) to O(d^2) (no need to store the last 3 digit sum, it
// is bound to be less than 10, jsut store the 2 digit and 1 digit)
// DONE