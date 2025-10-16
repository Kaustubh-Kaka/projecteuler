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

    int n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;

    vector<int> comb(n, 0);
    int m = 6;
    for (int i = 0; i < m; i++) comb[n - 1 - i] = 1;

    vector<vector<int>> combs;
    vector<int> cur;
    do {
        cur = {};
        for (int i = 0; i < n; i++)
            if (comb[i]) cur.push_back(i);
        combs.push_back(cur);
    } while (next_permutation(all(comb)));

    cout << combs.size() << '\n';

    auto good = [](const vector<int>& a, const vector<int>& b) {
        auto test = [](const vector<int>& a, const vector<int>& b, int d1,
                       int d2) {
            bool g1 = false, g2 = false;
            for (int j = 0; j < a.size(); j++)
                if (a[j] == d1 || (a[j] == 6 && d1 == 9) ||
                    (a[j] == 9 && d1 == 6))
                    g1 = true;
            for (int j = 0; j < b.size(); j++)
                if (b[j] == d2 || (b[j] == 6 && d2 == 9) ||
                    (b[j] == 9 && d2 == 6))
                    g2 = true;
            return g1 & g2;
        };

        int d1, d2;
        bool g1, g2;
        for (int i = 1; i < 10; i++) {
            d1 = (i * i) % 10, d2 = (i * i) / 10;
            if (!(test(a, b, d1, d2) || test(a, b, d2, d1))) return false;
        }
        return true;
    };

    reverse(all(combs));

    int cnt = 0;
    for (int i = 0; i < combs.size(); i++)
        for (int j = i + 1; j < combs.size(); j++)
            if (good(combs[i], combs[j])) cnt++;
    cout << cnt << '\n';

    /*
    probably the ugliest code I've written in a while lol, all I'm doing here
    is iterating over all 10C6 choices for dice faces and then iterating
    through all pairs of them to check if they are valid
    */

    return 0;
}
