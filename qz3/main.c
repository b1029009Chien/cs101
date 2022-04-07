#include <stdio.h>

FILE *hanoi_txt;
void rec_dec(char* s) {
   if (!*s) printf("\n");
   else {
       printf("%c,",*s++);
       rec_dec(s);
   }
}

int hanoi_tower(int n, char A, char B, char C) {
    if(n == 1) {         
        hanoi_txt = fopen("hanoi.txt", "a+");
        fprintf(hanoi_txt,"Move disk %d from %c to %c\n", n, A, C);  
        fclose(hanoi_txt);
    } else {        
        hanoi_tower(n-1, A, C, B);       
        hanoi_txt = fopen("hanoi.txt", "a+");
        fprintf(hanoi_txt,"Move disk %d from %c to %c\n", n, A, C);        
        fclose(hanoi_txt);
        hanoi_tower(n-1, B, A, C);
     }
}
    

int multiplication(int i, int j) {
    if(i==10) {
        return 0;
    } else if (j == 9) {
        printf("%d*%d = %d \n", i, j, i*j);
        multiplication(i+1, 1);
    } else {
        printf("%d*%d = %d ", i , j, i*j);
        multiplication(i, j+1);
    }
}

int main() {
    char s[]="1234567890";
    printf("func#1---------------------\n");
    rec_dec(s);
    printf("func#2---------------------\n");
    hanoi_tower(16,'A','B','C');
    printf("func#3---------------------\n");
    multiplication(1,1);

    return 0;
}

