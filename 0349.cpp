#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pair<int, int>> md = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

ll sp = 13265, sval = 1101, p = 104;
vector<ll> pdat(p, 0);

ll ans(ll n) { return sval + 12ll * ((n - sp) / p) + pdat[(n - sp) % p]; }

int main() {
    fast();

    int n = 200;

    vector<vector<bool>> grid(n, vector<bool>(n, true));

    pair<int, int> cpos = {n / 2, n / 2};
    int cdir = 0;

    int moves = 0;
    int bc = 0;

    while (moves < 1e6) {
        moves++;
        if (grid[cpos.first][cpos.second]) {
            cdir = (cdir + 3) % 4;
            bc++;
        } else {
            cdir = (cdir + 1) % 4;
            bc--;
        }
        grid[cpos.first][cpos.second] = !grid[cpos.first][cpos.second];
        cpos.first += md[cdir].first;
        cpos.second += md[cdir].second;
        if (cpos.first < 0 || cpos.first >= n || cpos.second < 0 ||
            cpos.second >= n)
            break;
        if (moves >= sp && moves < (sp + p)) {
            pdat[moves - sp] = bc - sval;
        }
    }

    ll rn = 1000000000;

    cout << ans(rn * rn) << '\n';

    return 0;
}
