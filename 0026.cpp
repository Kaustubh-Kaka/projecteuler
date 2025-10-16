#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int cs(int n) {
    int nc = n;
    while (nc % 5 == 0) nc /= 5;
    while (nc % 2 == 0) nc /= 2;
    if (nc == 1) return 0;

    vector<int> ls(n, -1);
    int r = 1;
    int it = 1;
    while (1) {
        if (ls[r] != -1)
            return it - ls[r];
        else
            ls[r] = it;
        r = (r * 10) % n;
        it++;
    }
    return -1;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int bval = 1, bind = 3;
    for (int i = 2; i <= 1000; i++)
        if (cs(i) > bval) {
            bval = cs(i);
            bind = i;
        }

    cout << bind << '\n';
    return 0;
}