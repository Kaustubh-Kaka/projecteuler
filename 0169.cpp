#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef __int128_t ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef long long li;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

li cnt = 0, truecalls = 0;

map<ll, ll> memo;

ll solve(ll n) {
    truecalls++;
    if (!memo[n]) {
        cnt++;
        if (n <= 1)
            memo[n] = 1;
        else {
            while (n % 2) n /= 2;
            if (n == 0)
                memo[n] = 1;
            else
                memo[n] = solve(n / 2) + solve(n / 2 - 1);
        }
    }
    return memo[n];
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    ll bnum = 1000000000000000000, snum = 10000000;

    cout << li(solve(bnum * snum)) << '\n';

    return 0;
}
