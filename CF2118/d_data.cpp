#include <bits/stdc++.h>

int main() {
    freopen("d.in", "w", stdout);
    int n = 2e5, k = 4, q =2e5;
    printf("1\n%d %d\n", n, k);
    for (int i = 1; i <= n; i++) 
        printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= n; i++) 
        printf("%d ", i % 4);
    printf("\n");
    printf("%d\n", q);
    for (int i = 1; i <= n; i++) 
        printf("%d ", i);
    printf("\n");
    return 0;
}