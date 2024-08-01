#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

long get_free_memory() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

long get_total_memory() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram;
}

int main() {
    long total_memory = get_total_memory();
    long target_memory = total_memory * 0.10;
    long allocated_memory = 0;
    long chunk_size = 1024 * 1024; // 1 MB
    void *ptr;
    void **allocated_ptrs = NULL; // Array to store allocated pointers
    size_t allocated_count = 0;

    while (get_free_memory() > target_memory) {
        ptr = malloc(chunk_size);
        if (ptr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            break;
        }
        allocated_count++;
        allocated_ptrs = realloc(allocated_ptrs, allocated_count * sizeof(void *));
        if (allocated_ptrs == NULL) {
            fprintf(stderr, "Reallocation failed\n");
            free(ptr);
            break;
        }
        allocated_ptrs[allocated_count - 1] = ptr;
        allocated_memory += chunk_size;
        printf("Allocated %ld MB, Free memory: %ld MB\n", allocated_memory / (1024 * 1024), get_free_memory() / (1024 * 1024));
    }

    printf("Finished: Total allocated memory: %ld MB\n", allocated_memory / (1024 * 1024));
    printf("Press Enter to free the allocated memory...\n");
    getchar(); // Wait for user to press Enter

    for (size_t i = 0; i < allocated_count; i++) {
        free(allocated_ptrs[i]);
    }
    free(allocated_ptrs);

    printf("Memory freed. Exiting...\n");

    return 0;
}
