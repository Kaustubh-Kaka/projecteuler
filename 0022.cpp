#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll sval(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) ans += ll(s[i] - 'A' + 1);
    return ans;
}

int main() {
    freopen("./22_names.txt", "r", stdin);

    vector<string> a;
    string s;
    cin >> s;
    string tt;
    for (int i = 0; i < s.size(); i++)
        if (s[i] < 'A' || s[i] > 'Z') {
            if (tt.size()) a.push_back(tt);
            tt = "";
        } else
            tt.push_back(s[i]);

    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) ans += ll(sval(a[i]) * (i + 1));
    cout << ans << '\n';
    return 0;
}