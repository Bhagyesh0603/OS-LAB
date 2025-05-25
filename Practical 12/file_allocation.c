#include <stdio.h> 
#include <stdlib.h> 
 
int disk[50] = {0}; 
 
void contiguous() { 
    int st, len, i, count = 0; 
    printf("\nContiguous Allocation\n"); 
    printf("Enter starting block and length of the file: "); 
    scanf("%d %d", &st, &len); 
 
    if (st < 0 || st + len > 50) { 
        printf("Invalid block range.\n"); 
        return; 
    } 
 
    for (i = st; i < st + len; i++) { 
        if (disk[i] == 0) 
            count++; 
    } 
 
    if (count == len) { 
        for (i = st; i < st + len; i++) { 
            disk[i] = 1; 
            printf("Block %d allocated.\n", i); 
        } 
        printf("Contiguous Allocation successful.\n"); 
    } else { 
        printf("Not enough contiguous free blocks.\n"); 
    } 
} 
 
void linked() { 
    int st, len, i, count = 0, allocated = 0, blocks[50]; 
    printf("\nLinked Allocation\n"); 
    printf("Enter starting block and length of the file: "); 
    scanf("%d %d", &st, &len); 
 
    if (st < 0 || st >= 50 || len <= 0 || len > 50) { 
        printf("Invalid input.\n"); 
        return; 
    } 
 
    if (disk[st] == 1) { 
        printf("Starting block is already allocated.\n"); 
        return; 
    } 
 
    blocks[allocated++] = st; 
    disk[st] = 1; 
 
    for (i = 0; i < 50 && allocated < len; i++) { 
        if (disk[i] == 0) { 
            blocks[allocated++] = i; 
            disk[i] = 1; 
        } 
    } 
 
    if (allocated == len) { 
        printf("Linked allocation chain: "); 
        for (i = 0; i < len - 1; i++) 
            printf("%d -> ", blocks[i]); 
        printf("%d\n", blocks[len - 1]); 
    } else { 
        printf("Not enough free blocks. Allocation failed.\n"); 
        for (i = 0; i < allocated; i++) 
            disk[blocks[i]] = 0; 
    } 
} 
 
void indexed() { 
    int indBlock, len, i, allocated = 0, blocks[50]; 
    printf("\nIndexed Allocation\n"); 
    printf("Enter index block and number of blocks needed: "); 
    scanf("%d %d", &indBlock, &len); 
 
    if (indBlock < 0 || indBlock >= 50 || len <= 0 || len > 49) { 
        printf("Invalid input.\n"); 
        return; 
    } 
 
    if (disk[indBlock] == 1) { 
        printf("Index block is already allocated.\n"); 
        return; 
    } 
 
    for (i = 0; i < 50 && allocated < len; i++) { 
        if (disk[i] == 0 && i != indBlock) { 
            blocks[allocated++] = i; 
        } 
    } 
 
    if (allocated == len) { 
        disk[indBlock] = 1; 
        for (i = 0; i < len; i++) 
            disk[blocks[i]] = 1; 
 
        printf("Index Block: %d\nAllocated Blocks: ", indBlock); 
        for (i = 0; i < len; i++) 
            printf("%d ", blocks[i]); 
        printf("\n"); 
    } else { 
        printf("Not enough free blocks.\n"); 
    } 
} 
 
int main() { 
    int choice, again; 
 
    do { 
        printf("\nFILE ALLOCATION MENU\n"); 
        printf("1. Contiguous Allocation\n"); 
        printf("2. Linked Allocation\n"); 
        printf("3. Indexed Allocation\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                contiguous(); 
                break; 
            case 2: 
                linked(); 
                break; 
            case 3: 
                indexed(); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice.\n"); 
        } 
 
        printf("\nDo you want to continue? (1 = Yes / 0 = No): "); 
        scanf("%d", &again); 
    } while (again == 1); 
 
    return 0; 
} 