#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    freopen("./0018data.txt", "r", stdin);

    int n = 15;
    vector<vector<int>> a(n, vector<int>(n)), dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) cin >> a[i][j];
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++) {
            dp[i][j] = a[i][j];
            if (j == 0)
                dp[i][j] += dp[i - 1][j];
            else if (j == i)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[n - 1][i]);
    cout << ans << '\n';
    return 0;
}