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
    // freopen("./input.txt", "r", stdin);

    int n = 200;
    vector<int> ch = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<int> dp(n + 1, 0), tf(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < ch.size(); i++) {
        tf = dp;
        for (int j = ch[i]; j < tf.size(); j++) {
            tf[j] += tf[j - ch[i]];
        }
        dp = tf;
    }
    cout << dp[200] << '\n';

    return 0;
}