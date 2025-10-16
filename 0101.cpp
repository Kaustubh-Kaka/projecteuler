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

        using ftype = long double;

    auto frac = [](ftype a) { return abs(a - round(a)); };

    auto eval = [](const vector<ftype>& a, ftype x) {
        ftype ans = 0;
        for (int i = a.size() - 1; i >= 0; i--) ans = x * ans + a[i];
        return ans;
    };

    auto polmult = [](const vector<ftype>& a, const vector<ftype>& b) {
        vector<ftype> c(a.size() + b.size() - 1, 0);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];
        return c;
    };

    auto lint = [&polmult](const vector<pair<ftype, ftype>>& a) {
        vector<ftype> res(a.size(), 0), temp;
        ftype dval;
        for (int i = 0; i < a.size(); i++) {
            temp = {1};
            dval = 1;
            for (int j = 0; j < a.size(); j++)
                if (i != j) {
                    temp = polmult(temp, {-a[j].first, 1});
                    dval *= (a[i].first - a[j].first);
                }
            dval /= a[i].second;
            for (int j = 0; j < a.size(); j++) res[j] += temp[j] / dval;
        }
        return res;
    };

    auto gs = [&eval](const vector<ftype>& a, const vector<ftype>& xpoints) {
        vector<pair<ftype, ftype>> ans(xpoints.size());
        for (int i = 0; i < xpoints.size(); i++)
            ans[i].first = xpoints[i], ans[i].second = eval(a, xpoints[i]);
        return ans;
    };

    auto fits = [&eval, &lint](const vector<ftype>& a) {
        cout << fixed << setprecision(10);

        int n = a.size();
        vector<pair<ftype, ftype>> plist;
        for (int i = 1; i <= n; i++) plist.push_back({i, eval(a, i)});

        for (int i = 0; i < n; i++)
            cout << plist[i].first << ' ' << plist[i].second << '\n';
        cout << '\n';

        vector<pair<ftype, ftype>> cur;
        vector<vector<ftype>> fitpols(n);
        for (int i = 0; i < n; i++) {
            cur.push_back(plist[i]);
            fitpols[i] = lint(cur);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < fitpols[i].size(); j++)
                fitpols[i][j] = round(fitpols[i][j]),
                cout << fitpols[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';

        int cans = 0;
        ftype ans = 0;

        for (int i = 0; i < n - 1; i++) {
            cans = 0;
            for (int j = 0; j < n; j++)
                if (abs(eval(fitpols[i], plist[j].first) - plist[j].second) >
                    1e-1) {
                    cans = j;
                    break;
                }
            cout << i + 1 << ' ' << cans + 1 << ' '
                 << eval(fitpols[i], plist[cans].first) << ' '
                 << plist[cans].second << '\n';
            ans += eval(fitpols[i], plist[cans].first);
        }
        cout << '\n' << ans << '\n';
    };

    vector<ftype> pol = {1};
    int n = 10;
    for (int i = 0; i < n; i++) pol.push_back(pol[i] * -1);

    fits(pol);

    /*
    the idea is to interpolate the points using polynomials of lower degrees
    and find the first point of difference from the actual data, this is done
    easily with lagrange interpolation with long double, the error never
    exceeds 0.1 for any of the coefficients
    */

    return 0;
}
