#include <stdio.h>

int my_strlen(char* s) {
    for (int i = 0;; i++) {
        if(s[i]==0) return i;
    }
}

int rec_strlen(char* s,int i) {
    if (i==0) return 1;
    return rec_strlen(i+1) ;
}

char* my_sort(char* s) {
    
}

int main() {
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    

    return 0;
}

