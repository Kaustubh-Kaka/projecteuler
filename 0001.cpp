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

    int n = 1000;
    n--;
    int a = 3;
    int b = 5;
    int i1 = n / a;
    int i2 = n / b;
    int i3 = n / (a * b);
    int s = a * (i1 + 1) * i1 / 2 + b * (i2 + 1) * i2 / 2 -
            a * b * (i3 + 1) * i3 / 2;
    cout << s << '\n';

    return 0;
}