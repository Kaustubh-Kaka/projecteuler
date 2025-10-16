#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool ispal(int n) {
    bool ans = true;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i]) {
            ans = false;
            break;
        }
    return ans;
}

bool bspal(int n) {
    string s;
    while (n) {
        if (n % 2)
            s.push_back('1');
        else
            s.push_back('0');
        n /= 2;
    }
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i]) {
            ans = false;
            break;
        }
    return ans;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 0;
    for (int i = 0; i <= int(1e6); i++)
        if (ispal(i) && bspal(i)) ans += i;
    cout << ans << '\n';

    return 0;
}