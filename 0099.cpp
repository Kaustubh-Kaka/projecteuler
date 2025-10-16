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
    FILE* f = fopen("99data.txt", "r");

    vector<pair<double, int>> a;
    double x1, x2;
    int ind = 1;
    while (ind <= 1000) {
        fscanf(f, "%lf,%lf", &x1, &x2);
        a.push_back({x2 * log(x1), ind});
        ind++;
    }
    fclose(f);
    sort(a.begin(), a.end());
    printf("%d\n", a[a.size() - 1].second);

    return 0;
}