#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void nextDay(vector<int>& a) {
    a[3] = (a[3] + 1) % 7;
    a[0]++;
    bool leapyear = false;
    if (a[2] % 4 == 0) leapyear = true;
    if (a[2] % 100 == 0) leapyear = false;
    if (a[2] % 400 == 0) leapyear = true;
    if ((a[0] == 29 && a[1] == 2 && leapyear == false) ||
        (a[0] == 30 && a[1] == 2 && leapyear == true)) {
        a[0] = 1;
        a[1]++;
    }
    if ((a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7 || a[1] == 8 ||
         a[1] == 10) &&
        a[0] == 32) {
        a[0] = 1;
        a[1]++;
    }
    if ((a[1] == 4 || a[1] == 6 || a[1] == 9 || a[1] == 11) && a[0] == 31) {
        a[0] = 1;
        a[1]++;
    }
    if (a[1] == 12 && a[0] == 32) {
        a[0] = 1;
        a[1] = 1;
        a[2]++;
    }
}

int main() {
    // freopen("./input.txt", "r", stdin);

    vector<int> curday = {1, 1, 1900, 1};

    int ans = 0;

    while (curday[2] < 2001) {
        nextDay(curday);
        if (curday[2] > 1900 && curday[0] == 1 && curday[3] == 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}