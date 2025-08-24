#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();

    int n = 30;

    vector<vector<ll>> dp(3, vector<ll>(2)), dpc = dp;
    dp[0][0] = 1;

    ll tans = 0;

    for (int i = 0; i < n; i++) {
        dpc[0][0] = dp[0][0] + dp[1][0] + dp[2][0];
        dpc[0][1] =
            dp[1][1] + dp[2][1] + dp[0][1] + dp[0][0] + dp[1][0] + dp[2][0];
        dpc[1][0] = dp[0][0];
        dpc[2][0] = dp[1][0];
        dpc[1][1] = dp[0][1];
        dpc[2][1] = dp[1][1];
        dp = dpc;
        tans = 0;

        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++) dpc[j][k] = 0;
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++) ans += dp[i][j];
    cout << ans << '\n';

    return 0;
}