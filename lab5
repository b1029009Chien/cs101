#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    return (int*)calloc(n,sizeof(int));
}

void set_value(int* p,int v) {
    *p = v;
}

void print_array(int* p, int n) {
    for (int i = 0; i<n; i++) {
        if(i==0) {
            printf("[ %d,",*p+i);
        } 
        if (i==n-1){
            printf("%d] ",*p+i);
        } 
        if(i>0&&i<n-1) {
            printf(" %d, ",*p+i);
        }
    }
}

typedef struct array_list {
    int n;
    int* (*func_get)(int);
    void (*func_set)(int*,int); 
    void (*func_print)(int*,int);
} array_list_t;

int main() {
    int n = 10;
    
    for (int i = 0; i<n; i++) {
        set_value(ip+i, i+1);
    }
    
    print_array(ip,n);
    free(ip);
    array_list_t file;
    file.n = 20;
    file.(*func_get)(int) = get_int_array;
    file.(*func_set)(int*,int) = set_value;
    file.(*func_print)(int*,int) = print_array;
    int* ip = get_int_array(n);
    
    return 0;
}
