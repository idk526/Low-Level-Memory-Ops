#include <stdio.h>
#include <stdint.h>

void inspect_memory_layout() {
    // 0xDEADBEEF is a classic magic number used in debugging and hacking
    int target_value = 0xDEADBEEF; 
    int *ptr = &target_value;

    printf("[*] ANALYZING STACK MEMORY LAYOUT...\n");
    printf("----------------------------------------\n");
    
    // Print the memory address where the value lives
    printf("[+] Address of target variable: %p\n", (void*)ptr);
    printf("[+] Value at target address:    0x%X\n", *ptr);

    // Pointer Arithmetic: Moving to the next memory block
    printf("----------------------------------------\n");
    printf("[*] Performing Pointer Arithmetic (+1 int step)...\n");
    
    ptr++; // Moves the pointer forward by sizeof(int)
    
    printf("[+] Next memory address:        %p\n", (void*)ptr);
    printf("[+] Value at next address:      %d (Garbage/Uninitialized)\n", *ptr);
}

int main() {
    inspect_memory_layout();
    return 0;
}
