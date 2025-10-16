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

    ll n = 100;

    cout << n * n * (n + 1) * (n + 1) / 4 - n * (n + 1) * (2 * n + 1) / 6
         << '\n';

    return 0;
}