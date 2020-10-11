#include <stdio.h>

#define VM_SIZE (1024 * 64) // Size in bytes of vm
#define NUM_FILE_HANDLES 8  // Number of simultaneous open files allowed
#define CELL_SIZE 2
#define SP0      6 * CELL_SIZE // Top of data stack
#define RP0      7 * CELL_SIZE // Top of return stack
#define SPP     33 * CELL_SIZE // Data stack pointer
#define RPP     34 * CELL_SIZE // Return stack pointer
#define TRUE    -1
#define FALSE    0
#define FORTH    4 * CELL_SIZE // Forth Vocabulary
#define TO_IN   17 * CELL_SIZE // >IN
#define NUM_TIB 18 * CELL_SIZE // #TIB
#define TIB     19 * CELL_SIZE // Text input buffer
#define CONTEXT 25 * CELL_SIZE // Current search vocabulary
#define CURRENT 27 * CELL_SIZE // Current vocabulary
#define CP      29 * CELL_SIZE // Code Pointer
#define NP      30 * CELL_SIZE // Next cell in name dictionary
#define LAST    31 * CELL_SIZE // Last name in dictionary
#define STATE   32 * CELL_SIZE // State of compiler
#define LIT         2
#define EXIT        3
#define INTERPRETER 0
#define WORDLIST    2
#define IMMEDIATE   3
struct IMAGE {
    char memory[VM_SIZE];
    FILE* file_handles[NUM_FILE_HANDLES];
};

extern int vm_run(struct IMAGE * image, int start);
extern void vm_init(struct IMAGE * image, FILE * fi, int size);
