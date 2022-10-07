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
		printf("불러올 내역 파일이 없습니다!");
	} 
		
	printf("\n==========================================================================================================\n");
	printf("\n\t\t\t\t발권내역 분석 시스템v3.22 Developed by DevFissler\n");
	printf("\n================================================ \[%10s\] ============================================\n",filename);
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","날짜","시간","이용권 종류","이용 시간","발권 수량","우대 구분","결제 금액");
	printf("\n==========================================================================================================\n");
	for (int index = 0; index < row; index++){
		printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[index],times[index],ticketAuth[index],ticketTime[index],ticketQuan[index],discountType[index],totalPrice[index]);
	}
	printf("\n==========================================================================================================\n");
	printf("\n=========================================== 일자  별 판매 현황 ===========================================\n\n");
	
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
		printf("\t\t\t\t\t%5d 월%5.2d 일:%10d 원\n",i/100,i%100,dateIncome[i]);
	}

}

void analyzePart ()
{
	printf("\n======================================== 이용권 시간 별 판매 현황 ========================================\n");
	
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
	printf("\n\t\t\t\t\t1 Day 이용권: 총 %d매\t / 매출 %d원\n",countFull,incomeFull);
	printf("\n\t\t\t\t\tAfter 4 이용권: 총 %d매\t / 매출 %d원\n",countAF4,incomeAF4);
	
	printf("\n======================================== 이용권 종류 별 판매 현황 ========================================\n");
	
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
	printf("\n\t\t\t\t\t종합 이용권: 총 %d매\t / 매출 %d원\n",countAll,incomeAll);
	printf("\n\t\t\t\t\t파크 이용권: 총 %d매\t / 매출 %d원\n",countPark,incomePark);
	
	printf("\n===================================== 우대 사항 분류 별 판매 현황 ========================================\n");
	
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
	printf("\n%15s\t%15s\t%15s\t%15s\t%15s\t%15s\n","없음","장애인","국가유공자","휴가장병","임산부","다둥이");
	printf("\n%15d\t%15d\t%15d\t%15d\t%15d\t%15d\n",countNo,countDis,countHonor,countVaca,countPreg,countMulti);
	printf("\n==========================================================================================================\n");
	printf("\n\t\t\t\t이용해주셔서 감사합니다!\n");
	printf("\n==========================================================================================================\n");
}

int main ()
{
	printingPart ();
	
	analyzePart ();
	
return 0;
}
