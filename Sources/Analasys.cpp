#include <stdio.h>
#include <ctime>
int row = 0;
int date[500],times[500],ticketAuth[500],ticketTime[500],ticketQuan[500],discountType[500],totalPrice[500];
	
void printingPart ()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int todayDate = (tm.tm_year+1900)*10000 + (tm.tm_mon+1)*100 + tm.tm_mday;
	const char* filename = "report.csv";
	
	FILE *fp = fopen(filename,"r");
	
	while ( fscanf(fp,"%d,%d,%d,%d,%d,%d,%d",&date[row],&times[row],&ticketAuth[row],&ticketTime[row],&ticketQuan[row],&discountType[row],&totalPrice[row]) !=-1){
		row++;
	}
	fclose(fp);
	
	if (row == 0){
		printf("�ҷ��� ���� ������ �����ϴ�!");
	} 
		
	printf("\n==========================================================================================================\n");
	printf("\n\t\t\t\t�߱ǳ��� �м� �ý���v3.22 Developed by DevFissler\n");
	printf("\n================================================ \[%10s\] ============================================\n",filename);
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","��¥","�ð�","�̿�� ����","�̿� �ð�","�߱� ����","��� ����","���� �ݾ�");
	printf("\n==========================================================================================================\n");
	for (int index = 0; index < row; index++){
		printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[index],times[index],ticketAuth[index],ticketTime[index],ticketQuan[index],discountType[index],totalPrice[index]);
	}
	printf("\n==========================================================================================================\n");
	printf("\n=========================================== ����  �� �Ǹ� ��Ȳ ===========================================\n\n");
	
	int dateIncome[5000]= {0,};
	
	for (int dateIndex = 101; dateIndex <= 1231; dateIndex++){
		for (int index = 0; index <= 5000 ; index++){
			if (dateIndex == date[index]%10000){
			dateIncome[dateIndex] += totalPrice[index];
			}
		}	
	}
	
	for (int i= 1; i<=2000; i++ ){
		if (dateIncome[i] >0)
		printf("\t\t\t\t\t%5d ��%5.2d ��:%10d ��\n",i/100,i%100,dateIncome[i]);
	}

}

void analyzePart ()
{
	printf("\n======================================== �̿�� �ð� �� �Ǹ� ��Ȳ ========================================\n");
	
	int countFull, countAF4, incomeFull, incomeAF4 = 0;
	
	for (int index=0; index < row; index++){
		if ( ticketTime[index] == 1) {
			countFull += ticketQuan[index];
			incomeFull += totalPrice[index];
		} 
		else {
			countAF4 += ticketQuan[index];
			incomeAF4 += totalPrice[index];
		}
	}
	printf("\n\t\t\t\t\t1 Day �̿��: �� %d��\t / ���� %d��\n",countFull,incomeFull);
	printf("\n\t\t\t\t\tAfter 4 �̿��: �� %d��\t / ���� %d��\n",countAF4,incomeAF4);
	
	printf("\n======================================== �̿�� ���� �� �Ǹ� ��Ȳ ========================================\n");
	
	int countAll, countPark, incomeAll, incomePark = 0;
	
	for (int index=0; index < row; index++){
		if ( ticketAuth[index] == 1) {
			countAll += ticketQuan[index];
			incomeAll += totalPrice[index];
		} 
		else {
			countPark += ticketQuan[index];
			incomePark += totalPrice[index];
		}
	}
	printf("\n\t\t\t\t\t���� �̿��: �� %d��\t / ���� %d��\n",countAll,incomeAll);
	printf("\n\t\t\t\t\t��ũ �̿��: �� %d��\t / ���� %d��\n",countPark,incomePark);
	
	printf("\n===================================== ��� ���� �з� �� �Ǹ� ��Ȳ ========================================\n");
	
	int countNo = 0 ; int countDis = 0 ; int countHonor =0 ; int countVaca = 0 ; int countPreg = 0; int countMulti = 0;
	
	for (int index=0; index < row; index++){
		if ( discountType[index] == 1) {
			countNo += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 2) {
			countDis += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 3) {
			countHonor += ticketQuan[index];
		}
		else if ( discountType[index] == 4) {
			countVaca += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 5) {
			countPreg += ticketQuan[index];		 
		}
		else {
			countMulti += ticketQuan[index];		 
		} 
	}
	printf("\n%15s\t%15s\t%15s\t%15s\t%15s\t%15s\n","����","�����","����������","�ް��庴","�ӻ��","�ٵ���");
	printf("\n%15d\t%15d\t%15d\t%15d\t%15d\t%15d\n",countNo,countDis,countHonor,countVaca,countPreg,countMulti);
	printf("\n==========================================================================================================\n");
	printf("\n\t\t\t\t�̿����ּż� �����մϴ�!\n");
	printf("\n==========================================================================================================\n");
}

int main ()
{
	printingPart ();
	
	analyzePart ();
	
return 0;
}
