#include <bits/stdc++.h>

const int maxn = 5e3 + 10, inf = 2e9;

int g[maxn][maxn], f[maxn][maxn];

int gcd(int x, int y) {
    if (g[x][y]) return g[x][y];
    if (!y) return g[y][x] = g[x][y] = x;
    return g[y][x] = g[x][y] = gcd(y, x % y);
}

int main() {
    int t, n, ans_gcd;
    int a[maxn];
    scanf("%d", &t);
    while (t--) {
        ans_gcd = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            ans_gcd = gcd(a[i], ans_gcd);
        }
        for (int i = 0; i < n; i++) {
            a[i] /= ans_gcd;
        }
        std::sort(a, a + n);
        if (a[0] == 1) {
            int ans = 0;
            for (int i = 0; i < n; i++)
                ans += a[i] > 1;
            printf("%d\n", ans);
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= a[n - 1]; j++)
                f[i][j] = inf;
            f[i][a[i]] = 0;
            if (i == 0) 
                continue;
            for (int j = 1; j <= a[n - 1]; j++) {
                f[i][gcd(a[i], j)] = std::min(f[i][gcd(a[i], j)], f[i - 1][j] + 1);
                f[i][j] = std::min(f[i][j], f[i - 1][j]);
            }
        }
        printf("%d\n", f[n - 1][1] + n - 1);
    }
    return 0;
}
/*
f[i][j] 前i个数，使其中一个变为j，最少步数
*/