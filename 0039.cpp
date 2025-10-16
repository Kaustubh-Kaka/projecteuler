#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int lim = 1e3;
    int rlim = 32;
    int a, b, c;
    vector<int> ssum;
    for (int i = 1; i <= rlim; i++)
        for (int j = i + 1; j <= rlim; j++) {
            a = j * j - i * i, b = 2 * i * j, c = i * i + j * j;
            if (gcd(a, b) == 1 && gcd(a, c) == 1 && gcd(b, c) == 1 &&
                (a + b + c < lim))
                ssum.push_back(a + b + c);
        }
    sort(ssum.begin(), ssum.end());
    vector<int> freq(lim + 1, 0);
    for (int i = 0; i < ssum.size(); i++)
        for (int j = 1; ssum[i] * j <= lim; j++) freq[ssum[i] * j]++;
    int ans, ansval = 0;
    for (int i = 0; i <= lim; i++)
        if (freq[i] > ansval) ans = i, ansval = freq[i];

    cout << ans << '\n';

    return 0;
}