#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int n,number, idnum, id, salary;
static char Time[32],date[32],name[32];


FILE *record_bin;
FILE *report_txt;
FILE *counter_bin;

void count_bin(FILE *counter_bin) {
    int write[1]= {0};
    int read[1]= {0};
    if((counter_bin=fopen("counter.bin","r"))==NULL) {//check file is exists?
        write[0]=1;//write 1 in to file
    } else { 
        write[0]=read[0]+1;//+1 time
    }
    number=write[0];//return number
}

typedef struct lotto_record {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[10];
    char lotto_time[10];
}lotto_record_t;

void recordset(FILE *record_bin) {
    time_t now = time(0);
    strftime(date, 32, "%Y%m%d",localtime(&now));
    strftime(Time, 32, "%H:%M:%S",localtime(&now));
    lotto_record_t record;
    record.lotto_no=number;
    record.lotto_receipt= (number*50*1.1);
    record.emp_id=id;
    strcpy(record.lotto_date, date);
	strcpy(record.lotto_time, Time);

	record_bin = fopen("records.bin","ab");
	fwrite(&record, sizeof(record), 1, record_bin);
	fclose(record_bin);
}

typedef struct {
    char lotto_Date[32];
    int sellnum, sellbox;
    int report_receipt;
}report_t;

typedef struct emp_record {
    int emp_ids;
    int emp_salary;
    char emp_name[10];
}emp_record_t;

int main() {
    
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
    count_bin(counter_bin);
    recordset(record_bin);
    report_t report_text;
    report_text.lotto_Date = date;
    report_text.sellnum = number;
    report_text.sellbox = n;
    report_text.report_receipt = record.lotto_receipt;
    fprintf(report_txt,"========= lotto649 Report =========\n");
    fprintf(report_txt, "--Date ------ Num. ------ Receipt\n");
    fprintf(report_txt, "%s      %d'/'%d     %d/n",Date,number,n,report_receipt);
    report_txt = fopen("report.bin","w+");
    fwrite(report,sizeof(report),1,report_txt);
    fclose(report_txt);
    return 0;
}


