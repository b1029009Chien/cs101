#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
static int number, idnum;

FILE *lottery_txt;
FILE *counter_bin;
FILE *operator_id;

void count_bin(FILE *counter_bin) {
    int write[1] = {0};//can don't need 0 because open file use "+" to establish file,so need to 0
    int read[1] = {0};
    if((counter_bin=fopen("counter.bin","r"))==NULL) {//check file is exists?
        counter_bin=fopen("counter.bin","wb+");//NO,open one file
        write[0]=1;//write 1 in to file
        fwrite(write,sizeof(int),1,counter_bin);
    } else { 
        counter_bin=fopen("counter.bin","rb+");//Yes,read it.
        fseek(counter_bin, 0, SEEK_SET);//seek to place 0 
        fread(read,sizeof(int),1,counter_bin);//read it, can write but don't need
        fclose(counter_bin);//close it
        write[0] = read[0]+1;//+1 time
        counter_bin=fopen("counter.bin","wb+");//open it
        fwrite(write, sizeof(int), 1, counter_bin);//+1
    }
    fclose(counter_bin);//close it
    number=write[0];//return number
}

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

void operator_idset(FILE *operator_id) {
    int id,writeid[6]={0};
    printf("please input operator id(0~5):");
    scanf("%d",&id);
    while(id>=0) {
        if(id>5) {
            printf("please input number again:");
            scanf("%d",&id);
        }else {
            break;
        }
    }//if num>5 need to input again
    
    operator_id = fopen("operator_id.bin", "w+");
    writeid[0] = id;
    fwrite(writeid, sizeof(int), 1, operator_id);
    fclose(operator_id);
    idnum = id;
}//write id num

int main() {
    int n, id, random;
    printf("Welcome to CGU lottery\n");
    operator_idset(operator_id);
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
    count_bin(counter_bin);
    sprintf(name,"lotto[%04d].txt",number);
    lottery_txt = fopen(name,"w+");
    //file name change
    
    fprintf(lottery_txt,"==========================\n");
    fprintf(lottery_txt,"=======+No.%05d+========\n",number);
    
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
    
    fprintf(lottery_txt,"=======*Op.%05d*=======\n", idnum);
    fprintf(lottery_txt, "========= csie@CGU =========");
    fclose(lottery_txt);
    printf("%d lottery you buy is(are) output to lotto.txt", n);
    
    return 0;
}



