#include <stdio.h>
#include <stdbool.h>
#define MAX 20
bool is_prime(int x) {
	int i;
    if (x < 2) return false;
    for (i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int n, i, hash, count = 0, hash_key, hash_ke, pf = 1;
    int arr[MAX];
    for (i = 0; i < MAX; i++) arr[i] = -1;
    printf("Enter number of available locations:");
    scanf("%d", &n);
    for (i = n - 1; i >= 1; i--) {
        if (is_prime(i)) {
            pf = i;
            break;
        }
    }
    while (count < n) {
        printf("Enter number: ");
        if (scanf("%d", &hash) != 1) break;
        hash_key = hash % n;
        if (arr[hash_key] == -1) {
            arr[hash_key] = hash;
        } else {
            i = 1;
            int step_size = pf - (hash % pf);
            hash_ke = hash_key;
            while (arr[hash_ke] != -1) {
                hash_ke = (hash_key + i * step_size) % n;
                i++;
                if (i > n) {
                    printf("Table full or probe sequence failed!\n");
                    goto end_input;
                }
            }
            arr[hash_ke] = hash;
        }
        count++;
    }
end_input:
    printf("\nHash Table Result:\n");
    for (i = 0; i < n; i++) {
        if (arr[i] == -1) printf("E\t");
        else printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
