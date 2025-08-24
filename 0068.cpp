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

    // freopen("./input.txt", "r", stdin);

    decltype(high_resolution_clock::now()) st, en;

    st = high_resolution_clock::now();

    int n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    auto fact = [](int n) {
        int ans = n;
        while (--n) ans *= n;
        return ans;
    };

    int temp = fact(10);

    auto cg = [](const vector<int>& a) {
        int n = a.size();
        int temp = a[0] + a[n / 2] + a[n / 2 + 1];

        for (int i = 0; i < n / 2; i++)
            if ((a[i] + a[(n / 2 + i)] + a[n / 2 + (i + 1) % (n / 2)]) != temp)
                return false;
        return true;
    };

    auto pv = [](const vector<int>& a) {
        int n = a.size();
        int cind = 0;
        for (int i = 0; i < n / 2; i++)
            if (a[i] < a[cind]) cind = i;

        string res;

        for (int i = 0; i < n / 2; i++) {
            res.append(to_string(a[(i + cind) % (n / 2)]));
            res.append(to_string(a[n / 2 + (i + cind) % (n / 2)]));
            res.append(to_string(a[n / 2 + (i + cind + 1) % (n / 2)]));
        }

        return res;
    };

    set<string> vlist;

    while (temp--) {
        if (cg(a)) vlist.insert(pv(a));
        next_permutation(all(a));
    }

    for (auto& x : vlist) cout << x << '\n';

    en = high_resolution_clock::now();
    cout << duration_cast<microseconds>(en - st).count() / 1000.0 << "ms\n";

    return 0;
}
