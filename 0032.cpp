#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool ispan(int n) {
    string s;
    bool good = false;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            s = to_string(i) + to_string(n / i) + to_string(n);
            sort(s.begin(), s.end());
            if (s == "123456789") {
                good = true;
                break;
            }
        }

    return good;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 0;
    for (int i = 0; i < int(1e4); i++)
        if (ispan(i)) ans += i;
    cout << ans << '\n';

    return 0;
}