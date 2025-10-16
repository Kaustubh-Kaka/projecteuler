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

    int n = 200;

    vector<int> cl(n + 1);
    for (int i = 1; i <= n; i++)
        cl[i] = [](int n) {
            if (n != 191)
                return 10;
            else
                return 11;
        }(i);

    vector<vector<pair<int, vector<int>>>> dp(n + 1);
    dp[1] = {{make_pair(0, vector<int>(1, 1))}};

    pair<int, vector<int>> temp;

    for (int i = 1; i <= n; i++) {
        sort(all(dp[i]));
        for (auto& x : dp[i])
            for (int k = 0; k < x.second.size(); k++) {
                int nstate = i + x.second[k];

                if (nstate <= n) {
                    temp = x;
                    temp.first++;
                    temp.second.push_back(nstate);
                    if (temp.first <= cl[nstate]) dp[nstate].push_back(temp);
                }
            }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) ans += (*dp[i].begin()).first;

    cout << ans << '\n';

    /*
    basically brute force while storing the past sequences, I'm not satisfied
    with this. I can probably get away with storing way fewer sequences as
    mentioned by some people in the thread, apparently if I only store the best
    sequence the answer only increases by 2, there is probably some heuristic I
    can use that is guarateed to be correct
    */

    return 0;
}
