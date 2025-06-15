#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
            printf("1");
        for (int i = k + 1; i <= n; i++)
            printf("0");
        printf("\n");
    }   
    return 0;
}