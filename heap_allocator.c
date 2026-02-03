#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t buffer_size = 64; // Allocating 64 bytes
    char *heap_buffer;

    printf("[*] REQUESTING HEAP MEMORY...\n");

    // Dynamic Memory Allocation (DMA)
    heap_buffer = (char *)malloc(buffer_size * sizeof(char));

    // Error Checking (Vital for secure code)
    if (heap_buffer == NULL) {
        fprintf(stderr, "[-] Critical Error: Memory allocation failed.\n");
        return 1;
    }

    printf("[+] Heap Memory allocated at Address: %p\n", (void*)heap_buffer);

    // Simulating a safe data write
    // Using strncpy instead of strcpy to prevent buffer overflow
    strncpy(heap_buffer, "SECURE_PAYLOAD_INIT", buffer_size);
    
    printf("[*] Data written to buffer: %s\n", heap_buffer);

    // Manual Memory Cleanup
    free(heap_buffer);
    printf("[+] Memory freed. Prevention of memory leak successful.\n");

    return 0;
}
