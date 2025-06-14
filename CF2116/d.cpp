#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, inf = 2e9;

int a[maxn], b[maxn], c[maxn], x[maxn], y[maxn], z[maxn];

int main() {
    int t, n, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            c[i] = b[i];
        }
        for (int i = 1; i <= q; i++)
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
        int fl = 0;
        for (int i = q; i >= 1; i--) {
            c[x[i]] = max(c[x[i]], c[z[i]]);
            c[y[i]] = max(c[y[i]], c[z[i]]);
            if (z[i] != x[i] && z[i] != y[i])
                c[z[i]] = 0;
        }
        for (int i = 1; i <= n; i++)
            a[i] = c[i];
        for (int i = 1; i <= q; i++)
            a[z[i]] = min(a[x[i]], a[y[i]]);
        for (int i = 1; i <= n; i++)
            if (a[i] != b[i]) {
                fl = 1;
                break;
            }
        if (fl) printf("-1\n");
        else {
            for (int i = 1; i <= n; i++)
                printf("%d ", c[i]);
            printf("\n");
        }
    }
    return 0;
}