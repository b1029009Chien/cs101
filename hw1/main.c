#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
static int number;

FILE *lottery_txt;

void print_7num(int random,int i,FILE *lottery_txt) {
    int r[6]={0};
    int k, j, num7;
    random += i;
    fprintf(lottery_txt,"[%d]: ", i);
    srand(random);
    for (k = 0 ;k<6 ;k++) {
        j = rand()%69+1;
        r[k] = j;
        for (int m = 0;m<k;m++) {
            if(r[k] == r[m]) {
                k -= 1;
                break;
            }
        }
    }//choose number 
    
    for (int a=0;a<5;a++) {
        for (int b = a+1;b<6;b++) {
            if (r[a]>r[b]) {
                int temp;
                temp = r[a];
                r[a] = r[b];
                r[b] = temp;
            }
        }
    }//compare number
    
    for (k=0;k<6;k++) {
        fprintf(lottery_txt,"%02d ",r[k]);
    }
    num7 = random %10+1;
    fprintf(lottery_txt,"%02d\n",num7);//special number
}

void print_nothing (int i,FILE *lottery_txt) {
    int k;
    fprintf(lottery_txt,"[%d]: ",i);
    for (k=1;k<=7;k++) {
        fprintf(lottery_txt,"-- ");
    }
    fprintf(lottery_txt,"\n");
}//no lottery put --

int main() {
    int n, id, random;
    printf("Welcome to CGU lottery\n");
    printf("How many lottery do you want to buy:");
    scanf("%d",&n);
    
    while(n>0) {
        if(n>5) {
            printf("please input number again:");
            scanf("%d",&n);
        }else {
            break;
        }
    }
    
    char name[100];
    sprintf(name,"lotto[%04d].txt",number);
    lottery_txt = fopen(name,"w+");
    //file name change
    
    fprintf(lottery_txt,"===========lotto649============\n");

    time_t curtime;
    time(&curtime);
    //time setup
    
    char* a= ctime(&curtime);
    size_t length=strlen(a);
    a[length-1]=0;
    //set char length
    
    fprintf(lottery_txt,"=%s=\n",a);
    
    srand((unsigned) time(NULL));
    random = rand();
    for (int i=1; i<= 5; i++) {
        if(i<=n) {
            print_7num(random, i, lottery_txt);
        } else {
            print_nothing(i,lottery_txt);
        }    
    }//produce rand number
    
    fprintf(lottery_txt, "========= csie@CGU =========");
    fclose(lottery_txt);
    printf("%d lottery you buy is(are) output to lotto.txt", n);
    
    return 0;
}
