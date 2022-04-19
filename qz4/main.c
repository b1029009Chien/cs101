#include <stdio.h>
#include <stdlib.h>

int func(int* n, int* m) {
    int tmp = *n;
    *n = *m;
    *m = tmp;
}

int swapArray(int* source, int* dest, int size){
    for(int i = 0;i < size;i++) {
        int tmp = *(source+i);
        *(source+i) = *(dest+i);
        *(dest+i) = tmp;
    }
}
 
void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) {
        if(i == (size-1)) {
            printf("%d]\n",*(array+i));
            break;
        }
    printf("%d,",*(array+i));
    }
}
    
char* copy_string(char* str) {
    for(int size = 0;;size++) {
        if(str[size] == 0) {
            break;
        }
        return (char*)calloc(size, sizeof(char));
    }
    for (int i = 0; i < 10 ; ++i) {
        str[i] = i;
    }
}

int main() {
    int n, m;
    n = 1;
    m = 2;
    func(&n,&m);
    printf("No1------------------------\n");
    printf("after swap n=%d,m=%d\n",n,m);
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2,1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swapArray(source, dest, size);
    printf("No2------------------------\n");
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("No3------------------------\n");
    printf("copy_string = %s\n",cp_str);
    free(cp_str);
    return 0;
}
