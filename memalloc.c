#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 100* 1024 * 1024; // 每次分配 100MB
    void *ptr;
    size_t allocations = 0;

    while (1) {
        ptr = malloc(size);
        if (ptr == NULL) {
            printf("Memory allocation failed %zu MB allocations.\n", sizeof(ptr));
            break;
        } else {
            printf("Memory allocation after %zu MB allocations.\n", sizeof(ptr));
        }
        allocations++;
    }

    printf("Press any key to exit...\n");
    getchar(); // 等待用戶按下任意鍵
    // 在這裡可以選擇釋放記憶體
    free(ptr);
    return 0;
}
