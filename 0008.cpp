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

    freopen("./0008data.txt", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) {
        string s, t;
        while (cin >> t) {
            s.append(t);
        }

        ll ans = 0, tans = 0;
        int n = s.size(), k = 13;
        for (int i = 0; i < n - k; i++) {
            tans = 1;
            for (int j = i; j < i + k; j++) tans *= ll(s[j] - '0');
            ans = max(ans, tans);
        }
        cout << ans << '\n';
    }
    return 0;
}