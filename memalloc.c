#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024 * 1024; // 每次分配 1MB
    void *ptr;
    size_t allocations = 0;

    while (1) {
        ptr = malloc(size);
        if (ptr == NULL) {
            printf("Memory allocation failed after %zu allocations.\n", allocations);
            break;
        }
        allocations++;

        // 在這裡可以選擇釋放記憶體
        free(ptr);
    }

    printf("Press any key to exit...\n");
    getchar(); // 等待用戶按下任意鍵

    return 0;
}
