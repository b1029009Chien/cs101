#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE* lottery;
FILE* binfile;
FILE* operatorId;
FILE* recordsfile; 

static int currentCount;
static int id,ida[1];
static char date[32];
static char Time[32];
int num[7]={0};

typedef struct lottoRecord{
	int lotto_no; //= currentCount
	int lotto_receipt; //= currentCount *55
	int emp_id; //= id
	char lotto_date[32]; //= date
	char lotto_time[32]; //= Time
}lotto_record_t;


void setRecords(){
	time_t curtime = time(0);
	lotto_record_t doRecord;
	doRecord.lotto_no = currentCount;
	doRecord.lotto_receipt = currentCount*55;
	doRecord.emp_id = id;
	strftime(doRecord.lotto_date,100, "%Y%m%d", localtime(&curtime));
	strftime(doRecord.lotto_time,100, "%H:%M:%S", localtime(&curtime));

	recordsfile = fopen("records.bin","ab");
	fwrite(&doRecord, sizeof(doRecord), 1, recordsfile);
	fclose(recordsfile);
}

typedef struct empRecord{
	int emp_id; //= id
	char emp_name[32]; //= iu
	int emp_salary;//98000
}emp_record_t ;
emp_record_t emprecord;

int operator_id(char name[],int salary){
	printf("請輸入要新增操作人員ID(1-99) : \n");
	scanf("%d", &id);
	printf("請輸入要新增操作人員Name : \n");
	scanf("%s", &name);
	printf("請輸入要新增操作人員Salary : \n");
	scanf("%d", &salary);
	printf("輸入完成\n");
	
	emprecord.emp_id = id;
	for(int i = 0 ; i < 50 ; i++) {
		emprecord.emp_name[i] = name[i];
	}	
	emprecord.emp_salary =salary;
	
	operatorId = fopen("operator_id.bin","ab");
	fwrite(&emprecord, sizeof(emprecord), 1, operatorId);
	fclose(operatorId);
	return 0;
}

void countTimes(){
    int read[1];
    int write[1];    
    if((binfile= fopen("binfile.txt", "r")) == NULL){
        binfile = fopen("binfile.txt", "wb+");
        write[0] = 1;       
        fwrite(write, sizeof(int), 1, binfile);
    }
    else{
        binfile = fopen("binfile.txt", "rb+");
        fseek(binfile, 0, SEEK_SET);
        fread(read, sizeof(int), 1, binfile);
        fclose(binfile);    
        write[0] = read[0] + 1;
        binfile = fopen("binfile.txt", "wb+");
        fwrite(write, sizeof(int), 1,binfile);
    }
    fclose(binfile);
    currentCount = write[0];
} 

void lotto(){
    int var,exist,tmp,n=0;
    for(int i=0;i<7;i++){
        num[i]=0;
    }
    while(n<6){
        var=rand()%69+1;
        exist=0;
        for(int i=0;i<=n;i++){
            if(num[i]==var){
                exist=1;
            }
        }
        if(exist==0){
            num[n]=var;
            n++;
        }
    }
    for(int i=0;i<6;++i){
        for(int j=0;j<i;++j){
            if(num[j]>num[i]){
                tmp=num[j];
                num[j]=num[i];
                num[i]=tmp;
            }
        }
    }    
    num[6]=rand()%10+1;
    for(int i=0;i<7;i++){
        fprintf(lottery,"%02d ",num[i]);
    }
}

int main()
{
	
    int n,id,salary;
	char currentName[80];
	char name[50];
    srand(time(NULL));
    
    printf("請輸入操作人員id(0~5):");
    scanf("%d",&id); 
	if(id==0){
		operator_id(name,salary);
	}else{
    	printf("請問您要買幾組樂透彩:");
		scanf("%d",&n);
        printf("購買的%d組樂透組合在 lotto.txt\n", n);
    	countTimes();

    	sprintf(currentName, "lotto[%04d].txt", currentCount);
   		lottery= fopen(currentName,"w+");
    	fprintf(lottery,"========lotto649=========\n");
    	time_t curtime;
    	time(&curtime);
    	fprintf(lottery,"=%s",ctime(&curtime));
    	fprintf(lottery,"========+ No.%04d +======\n", currentCount);    
    	for(int i=1;i<=n;i++){
    	    fprintf(lottery,"[%d]:",i);
    	    lotto();
    	    fprintf(lottery,"\n");
    	}
    	for(int j=0;j<(5-n);j++){
    	    fprintf(lottery,"[%d]:",j+n+1);
        	for(int k=0;k<7;k++){
            	fprintf(lottery,"-- ");
        	}
        	fprintf(lottery,"\n");
    	}
    	fprintf(lottery,"=======*Op.%05d  *======\n",id);    
    	fprintf(lottery,"========csie@CGU ========");
    	fclose(lottery);
    }
    setRecords();
}

