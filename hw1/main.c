#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_7num(int random,int i,FILE *lottery_txt) {
    int r[7]={0};
    int k;
    int j;
    int num7;
    random+=i;
    fprintf(lottery_txt,"[%d]: ",i);
    srand(random);
    for(k=0;k<7;k++) {
        j = rand()%69+1;
        r[k]=j;
        for(int m=0;m<k;m++) {
            if(r[k]==r[m]) {
                k-=1;
                break;
            }
        }
    }
    for (int a=0;a<6;a++) {
        for (int b=a+1;b<7;b++) {
            if(r[a]>r[b]) {
                int temp;
                temp=r[a];
                r[a]=r[b];
                r[b]=temp;
            }
        }
    }
    for (k=0;k<7;k++) {
        fprintf(lottery_txt,"%02d ",r[k]);
    }
    num7 = random %10+1;
    fprintf(lottery_txt,"%02d\n",num7);
}

void print_nothing (int i,FILE *lottery_txt) {
    int k;
    fprintf(lottery_txt,"[%d]: ",i);
    for (k=1;k<=7;k++) {
        fprintf(lottery_txt,"-- ");
    }
    fprintf(lottery_txt,"\n");
}

int main() {
    FILE *lottery_txt;
    int n,random;
    printf("Welcome to CGU lottery\n How many lottery do you want to buy:");
    scanf("%d",&n);
    
    //n=6
    lottery_txt=fopen("lottery.txt","w+");
    fprintf(lottery_txt,"========= lotto649 =========\n");
    
    time_t curtime;
    time(&curtime);
    //time setup
    
    char* a= ctime(&curtime);
    size_t length=strlen(a);
    a[length-1]=0;
    //set char length
    fprintf(lottery_txt,"=%s=\n",a);
    while(n>0) {
        if(n>5) {
            printf("please input number again:");
            scanf("%d",&n);
        }else {
            break;
        }
    }
    srand((unsigned) time(NULL));
    random = rand();
    for(int i=1; i<=6; i++) {
        if(i<=n) {
            print_7num(random, i, lottery_txt);
        } else {
            print_nothing(i,lottery_txt);
        }    
    }
    fprintf(lottery_txt, "========= csie@CGU =========");
    fclose(lottery_txt);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt", n);
    
    
    return 0;


}

