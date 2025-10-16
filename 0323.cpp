#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// #pragma GCC target("avx2")

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

    using ftype = double;

    int n = 32;
    vector<ftype> dp(n + 1, 0);

    auto ncr = [](int n, int r) {
        ftype ans = 1;
        for (int i = n; i >= n - r + 1; i--) ans *= (ftype)i;
        for (int i = 1; i <= r; i++) ans /= (ftype)i;
        return ans;
    };

    auto tnp = [](int n) {
        ftype ans = 1;
        for (int i = 0; i < n; i++) ans /= 2.0;
        return ans;
    };

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) dp[i] += ncr(i, i - j) * tnp(i) * dp[j];
        dp[i] /= (1 - tnp(i));
    }

    cout << fixed << setprecision(10) << dp[n] << '\n';

    /*
    the idea is to construct a markov chain each node denotes how many zeroes
    are still left in the number, the transtitions are now trivial since we
    don't care about the positions where we have 1s and to go from k to k - i we
    have iCk * 2^(n - k) valid numbers and consequently the probability
    (k -> k - i) = iCk * 2^(n - k), the rest is trivial
    */

    return 0;
}
