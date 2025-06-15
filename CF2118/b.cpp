#include <bits/stdc++.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", n * 2 - 1);
        printf("%d %d %d\n", 1, 1, n);
        for (int i = 2; i <= n; i++)
            printf("%d %d %d\n%d %d %d\n", i, 1, i - 1, i, i, n);
    }
    return 0;
}