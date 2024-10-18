#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    // Define a string
    char str[] = "😊Hello";

    // Print the string normally
    printf("Original string: \"%s\"\n", str);

    // Cast the string to an integer pointer (int*)
    int* int_ptr = (int *)str;

    // Print the string interpreted as an integer
    printf("Casting string at %p as a a 32-bit (4 byte) integer: 0x%x (hex) %d (dec)\n", int_ptr, *int_ptr, *int_ptr);
    // This prints: Casting string as a 32-bit (4 byte) integer: 0x6c6c6548 (hex) 1819043144 (dec)
    // Here, 6c -> l, 65 -> e, 48 -> H. So it represents Hell (backwards).
    // It does not write o because it is being converted to an int, which can only hold 4 characters.

    // Let's interpret the string as a series of bytes (unsigned char*)
    // unsigned char *byte_ptr = (unsigned char *)str;
    // printf("String at %p as a series of bytes: ", byte_ptr);
    // for (int i = 0; i < strlen(str); i++) {
    //     printf("0x%02X ", byte_ptr[i]);
    // }
    // printf("\n");

    // return 0;

    // Now cast the string to a pointer to a uint64_t (treat 8 bytes as one number)
    // uint64_t *long_ptr = (uint64_t *)str;
    // printf("Casting string as a 64-bit (8 byte) integer 0x%llx (hex) %llu (dec)\n", *long_ptr, *long_ptr);

    // // Demonstrate how casting can cause unexpected results
    char *new_str = (char *)int_ptr;
    printf("Interpreting integer pointer as a string again: %s\n", new_str);

    // // Let's modify the first 4 bytes of the string through an int pointer
    *int_ptr = 0x41414141; // This writes 'AAAA' in the first 4 bytes of the string

    // // Show the modified string
    printf("Modified string after writing \"AAAA\": \"%s\"\n", str);

    return 0;
}
