#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    ll ans = 0;

    int dig = 100;
    vector<vector<ll>> dp(dig, vector<ll>(10, 0));
    for (int i = 1; i < 10; i++) dp[0][i] = 1;
    for (int i = 0; i < dig - 1; i++) {
        for (int j = 0; j < 10; j++)
            for (int k = j; k < 10; k++) {
                dp[i + 1][k] += dp[i][j];
            }
    }

    vector<vector<ll>> dp2(dig, vector<ll>(10, 0));
    for (int i = 1; i < 10; i++) dp2[0][i] = 1;
    for (int i = 0; i < dig - 1; i++) {
        for (int j = 0; j < 10; j++)
            for (int k = j; k >= 0; k--) {
                dp2[i + 1][k] += dp2[i][j];
            }
    }

    for (int i = 0; i < dig; i++) {
        for (int j = 0; j < 10; j++) {
            // cout << dp[i][j] << ' ';
            ans += dp[i][j];
        }
        // cout << '\n';
    }

    for (int i = 0; i < dig; i++) {
        for (int j = 0; j < 10; j++) {
            // cout << dp2[i][j] << ' ';
            ans += dp2[i][j];
        }
        // cout << '\n';
    }

    cout << ans - 9 * dig << '\n';
    return 0;
}
