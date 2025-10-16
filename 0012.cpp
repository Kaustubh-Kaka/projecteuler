#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<ll> plist;

ll ndiv(ll n) {
    ll td = 0, ans = 1;
    for (int i = 0; i < plist.size() && plist[i] * plist[i] <= n; i++)
        if (n % plist[i] == 0) {
            td = 0;
            while (n % plist[i] == 0) {
                n /= plist[i];
                td++;
            }
            ans *= td + 1;
        }
    if (n > 1) ans *= 2;
    return ans;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int pcap = 1e3;

    vector<bool> erat(pcap + 1, true);
    for (int i = 2; i * i <= pcap; i++) {
        if (erat[i])
            for (int j = 2; i * j <= pcap; j++) erat[i * j] = false;
    }

    for (int i = 2; i <= pcap; i++)
        if (erat[i]) plist.push_back(i);

    ll ind = 1;
    while (ndiv(ind * (ind + 1) / 2) < 500) ind++;
    cout << ind * (ind + 1) / 2 << '\n';
    return 0;
}