#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int number, idnum;
static int n, number, id, salary;
static char date[32];

FILE *record_bin;
FILE *report_txt;

typedef struct lotto_record {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[16];
}lotto_record_t;

typedef struct stat {
    int lotto_counter;
    int lotto_numset;
    int lotto_receipt;
    char lotto_date[16];
} stat_t;

void timeset() {
    time_t now = time(0);
    strftime(date, 32, "%Y%m%d",localtime(&now));
}

int check_date_in_table(lotto_record_t tmp, stat_t stat_table[], int TSIZE) {
    int i = -1;
    for(i = 0; i<TSIZE; i++) {
        if(strcmp(tmp.lotto_date, stat_table[i].lotto_date) == 0) {
            break;
        }
        if(i >= TSIZE) {
            return -1;
        }
        return i;
    }
}

void record_txtset(stat_t stat_table[], int TSIZE) {
    int total= 0;
    int total_num = 0, total_numset = 0, total_receipt = 0, groupsum = 0;
    FILE* report_txt = fopen ("report.txt","w+");
    fprintf(report_txt,"========= lotto 649 Report ========\n");
    fprintf(report_txt,"- Date ------ Num. ------ Receipt -\n");
    
    for(int i = 0; i< TSIZE;i++) {
        fprintf(report_txt, "%s\t\t%d/%d\t\t\t%d\n",stat_table[i].lotto_date,
        stat_table[i].lotto_counter, stat_table[i].lotto_numset, stat_table[i].lotto_receipt);
    
    total++;
    total_num += stat_table[i].lotto_counter;
    total_numset += stat_table[i].lotto_receipt;    
    }
    
    fprintf(report_txt,"--------------------------------------\n");
    fprintf(report_txt,"%d\t\t\t\t%d/%d\t\t%d\n",total,total_num,total_numset,total_receipt);
    timeset();
    fprintf(report_txt,"======== %s Printed =========", date);
    fclose(report_txt);
    
}

int main() {
    const int TSIZE = 128;
    lotto_record_t tmp;
    int table_index = 0;
    int date_index = -1;
    stat_t stat_table[128] = {0};
    FILE* record_bin = fopen("record.bin","rb");
    while (fread(&tmp,sizeof(lotto_record_t),1,record_bin)) {
        if((date_index = check_date_in_table(tmp , stat_table, 128)) <0) {
        date_index = number++;
        strcpy(stat_table[date_index].lotto_date, tmp.lotto_date);
        }
        stat_table[date_index].lotto_counter++;
        stat_table[date_index].lotto_receipt += tmp.lotto_receipt;
        stat_table[date_index].lotto_numset += (tmp.lotto_receipt/55);;
    }
    fclose(record_bin);
    record_txtset(stat_table, table_index);
    
    return 0;
}
