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

    auto soe = [](int n) {
        vector<bool> a(n + 1, true);
        for (int i = 2; i * i <= n; i++)
            if (a[i])
                for (int j = i; i * j <= n; j++) a[i * j] = false;
        a[0] = a[1] = false;
        return a;
    };

    auto dc = [](int n) {
        int ans = 0;
        while (n) ans++, n /= 10;
        return ans;
    };

    int n = 1e7;
    auto isp = soe(n);

    vector<int> dp(n + 1, n + 1);
    dp[2] = 2;

    int temp, mult, cur, curd;

    queue<int> bfs;
    bfs.push(2);

    while (bfs.size()) {
        cur = bfs.front();
        bfs.pop();

        temp = dc(cur), mult = 1;
        dp[cur] = max(cur, dp[cur]);

        for (int i = 0; i < temp; i++) {
            curd = (cur / mult) % 10;
            for (int j = (0 + (i == temp - 1)); j < 10; j++) {
                if (cur + (j - curd) * mult <= n &&
                    dp[cur + (j - curd) * mult] > dp[cur] &&
                    dp[cur + (j - curd) * mult] > (cur + (j - curd) * mult) &&
                    isp[cur + (j - curd) * mult])
                    dp[cur + (j - curd) * mult] = dp[cur],
                                          bfs.push(cur + (j - curd) * mult);
            }
            mult *= 10;
        }

        for (int i = 1; i < 10; i++)
            if (i * mult + cur <= n && dp[i * mult + cur] > dp[cur] &&
                dp[i * mult + cur] > (i * mult + cur) && isp[i * mult + cur])
                dp[i * mult + cur] = dp[cur], bfs.push(i * mult + cur);
    }

    ll ans = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
        if (isp[i] && dp[i] > i) ans += i, cnt++;
    cout << ans << ' ' << cnt << '\n';

    /*
    the idea is to do bfs so as to minimize the largest prime encountered in the
    chain that leads to the current prime, the nodes are primes and the
    transitions are all the valid steps. a simple optimization is used to make
    sure that primes for whome chains with maximum prime <=p have been found are
    not updated further.
    */

    return 0;
}
