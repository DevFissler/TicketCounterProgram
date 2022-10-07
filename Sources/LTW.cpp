#include <stdio.h>
#include <ctime>	

int row = 0;
int reportArray[50000][6] = {0};
	
int ticketAuth,ticketTime,ticketQuan,idNumber,fullAge,
	discountType,totalPrice,contiChoice;

void startresetPart () {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);	
	int todayDate = (tm.tm_year+1900)*10000 + (tm.tm_mon+1)*100 + tm.tm_mday;
	int todayTime = tm.tm_hour * 100 + tm.tm_min;
	
	int ticketAuth,ticketTime,ticketQuan,idNumber,fullAge,
		discountType,totalPrice,contiChoice = 0;
	
	
	printf("\n============================================================================================\n");
	printf("\n\n\t\t\t티켓 발권 시스템v3.24 Developed by DevFissler\n\n");
	printf("발권일시: %d %d:%.2d\t",todayDate,tm.tm_hour,tm.tm_min);printf("\t\t\t\t   발권 번호 : %d-%.4d",todayDate,row+1);
}	

void questionPart() {
	do{
		printf("\n========================================= 이용권 종류 ======================================\n");
		printf("\n\t\t\t\t%-10s\t%-10s\n", "1.종합 이용권", "2. 파크 이용권\n");
		printf("\n\t\t\t\t[1] 이용권의 종류를 선택하세요: ");
		scanf("%d",&ticketAuth);
		if (ticketAuth == 1|| ticketAuth == 2){
			continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketAuth == 1|| ticketAuth == 2));
	
	do{
		printf("\n========================================= 이용   시간 ======================================\n");
		printf("\n\t\t\t\t%-10s\t%-10s\n", "1.1 Day ", "2. After 4\n");
		printf("\n\t\t\t\t[2] 이용 시간을 선택하세요:  ");
		scanf("%d",&ticketTime);
		if (ticketTime == 1|| ticketTime == 2){
			continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketTime == 1|| ticketTime == 2));

	do{
		printf("\n========================================= 연령   구분 ======================================\n");
		printf("\n\t\t\t\t[3] 주민등록번호 앞 6자리를  입력하세요: ");  
		scanf("%d",&idNumber);
		if ( idNumber%10000 <= 1231 && idNumber%10000 >= 101 && idNumber%100 <= 31 && idNumber <= 991231) {// 생년월일 가능범위 설정 
		continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (idNumber%10000 <= 1231 && idNumber%10000 >= 101 && idNumber%100 <= 31 && idNumber <= 991231));	
	
	do{
		printf("\n========================================= 발권   수량 ======================================\n");
		printf("\n\t\t\t\t[4] 발권할  티켓  수를 입력하세요(최대 10매): ");
		scanf("%d",&ticketQuan);
		if (ticketQuan <= 10){
			continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketQuan <= 10));
	
	do{
		printf("\n========================================= 우대   사항 ======================================\n");
		printf("\n\t\t\t\t1. 없음(경로 우대는 자동처리)\n");
		printf("\t\t\t\t2. 장애인\n"); //동반 1인 50% 
		printf("\t\t\t\t3. 국가유공자\n"); //동반 1인 50% 
		printf("\t\t\t\t4. 휴가 장병\n"); // 동반 1인 49% 
		printf("\t\t\t\t5. 임산부\n");  // 본인만 50% (파크는 x) 
		printf("\t\t\t\t6. 다둥이 행복카드\n"); // 본인만 30% (파크는 x) 
		printf("\n\t\t\t\t[5] 우대사항을 선택하세요 : ");
		scanf("%d",&discountType);
		if (discountType <= 6){
			continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (discountType <= 6));
}

void calculationPart () {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);	
	int todayDate = (tm.tm_year+1900)*10000 + (tm.tm_mon+1)*100 + tm.tm_mday;
	int todayTime = tm.tm_hour * 100 + tm.tm_min;
	
	int birthYear, unitPrice = 0;
	int birthDate = idNumber%10000;
	float discountRate = 0.0;
	
	switch (discountType){
		case (1) : 
		discountRate = 0.0;
		break;
		case (2) :
		discountRate = 0.5;
		break;
		case (3) :
		discountRate = 0.5;
		break;
		case (4) :
		discountRate = 0.49;
		break;
		case (5) :
		discountRate = 0.5;
		break;
		case (6) :
		discountRate = 0.3;
		break;
	}
	
	if ( idNumber / 10000 < 22){  // 출생 년도 계산 
		birthYear = 2000 + idNumber / 10000;
	}
	else{
		birthYear = 1900 + idNumber / 10000;
	}
		
	if ( birthDate <= (tm.tm_mon+1)*100+tm.tm_mday) { //생일 지남 
		fullAge = tm.tm_year + 1900 - birthYear;
	}
	else {
		fullAge = tm.tm_year + 1900 - birthYear - 1;
	}
		
	if (fullAge >= 65){  //경로우대자는 할인 적용 x 
		discountRate = 0.0;
	}
	
	const int 	ALL_ALL_ADULT  = 59000, ALL_ALL_YOUTH  = 52000, ALL_ALL_KIDS  = 47000, ALL_ALL_BABY  = 15000, // 3살 ~ 12 살 어린이 , 만 13세 ~ 만 18세 청소년, 만 65세 이상 어린이요금 
				ALL_AF4_ADULT  = 48000, ALL_AF4_YOUTH  = 42000, ALL_AF4_KIDS  = 36000, ALL_AF4_BABY  = 15000,
				PARK_ALL_ADULT = 56000, PARK_ALL_YOUTH = 50000, PARK_ALL_KIDS = 46000, PARK_ALL_BABY = 15000,
				PARK_AF4_ADULT = 45000, PARK_AF4_YOUTH = 40000, PARK_AF4_KIDS = 35000, PARK_AF4_BABY = 15000; // 3차원 배열로? 

	if (ticketAuth == 1){
		if (ticketTime == 1){
			if(fullAge >= 19 && fullAge < 65){
				unitPrice = ALL_ALL_ADULT;
			}	
			else if (fullAge >= 13 && fullAge < 19){
				unitPrice = ALL_ALL_YOUTH;
			}
			else if (fullAge >= 3 && fullAge < 13){
				unitPrice = ALL_ALL_KIDS;
			}
			else {
				unitPrice = ALL_ALL_BABY;
			}
		}
		else if (ticketTime == 2){
			if(fullAge >= 19 && fullAge < 65){
				unitPrice = ALL_AF4_ADULT;
			}
			else if (fullAge >= 13 && fullAge < 19){
				unitPrice = ALL_AF4_YOUTH;
			}
			else if (fullAge >= 3 && fullAge < 13){
				unitPrice = ALL_AF4_KIDS;
			}
			else {
				unitPrice = ALL_AF4_BABY;
			}
		}
	}
	else {
		if (ticketTime == 1){
			if(fullAge >= 19 && fullAge < 65){
				unitPrice = PARK_ALL_ADULT;
			}
			else if (fullAge >= 13 && fullAge < 19){
				unitPrice = PARK_ALL_YOUTH;
			}
			else if (fullAge >= 3 && fullAge < 13){
				unitPrice = PARK_ALL_KIDS;
			}
			else {
				unitPrice = PARK_ALL_BABY;
			}
		}
		else if (ticketTime == 2){
			if(fullAge >= 19 && fullAge < 65){
				unitPrice = PARK_AF4_ADULT;
			}
			else if (fullAge >= 13 && fullAge < 19){
				unitPrice = PARK_AF4_YOUTH;
			}
			else if (fullAge >= 3 && fullAge < 13){
				unitPrice = PARK_AF4_KIDS;
			}
			else {
				unitPrice = PARK_AF4_BABY;
			}
		}
	}
	
	if ( discountType <5 ) {
		if (ticketQuan == 1){
			totalPrice = unitPrice * (1 - discountRate); //1인 할인 
		}
		else {
			totalPrice = unitPrice * (ticketQuan - discountRate * 2); //동반 할인 
		}
	}
	else {
		if (ticketAuth == 1) {
			totalPrice = unitPrice * (ticketQuan - discountRate); //1인 할인 
		}
		else
			totalPrice = unitPrice * ticketQuan; // 파크 이용권은 할인 혜택 x 
	}
}

void resultPart() {
	printf("\n========================================= 발권   결과 ======================================\n");
	printf("\n\t\t\t\t나이 : 만 %d세\t/ 구분 : ",fullAge); 
			
	if (fullAge >= 65){
		printf("경로");
	}
	else if(fullAge >= 19 && fullAge < 65){
		printf("일반");
	}
	else if (fullAge >= 13 && fullAge < 19){
		printf("청소년");
	}
	else if (fullAge >= 3 && fullAge < 13){
		printf("어린이"); 
	}
	else {
		printf("유아"); 
	}
	
	printf("\n\n\t\t\t\t총 %d 장 발권, 입장료 총액은 %d 원 입니다.\n",ticketQuan,totalPrice);
	printf("\n============================================================================================\n");
	
	reportArray[row][0] = ticketAuth;
	reportArray[row][1] = ticketTime;
	reportArray[row][2] = ticketQuan;
	reportArray[row][3] = discountType;
	reportArray[row][4] = fullAge;
	reportArray[row][5] = totalPrice;
	
	do {
		printf("\n\t\t\t\t%-10s\t%-10s\n", "1. 계속 발권", "2. 발권 종료\n");
		printf("\n\t\t\t\t계속 발권 하시겠습니까? : "); 
		scanf("%d",&contiChoice);	
		if (contiChoice == 1|| contiChoice == 2){
			continue;
		}
		printf("\n============================================================================================\n");
		printf("\n\t\t\t\t잘못된 입력입니다! 다시 입력해 주세요.\n");
		printf("\n============================================================================================\n");
	} while (! (contiChoice == 1|| contiChoice == 2));
	
	if (contiChoice ==1){
		row++;
	}
}

void endsystemPart(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);	
	int todayDate = (tm.tm_year+1900)*10000 + (tm.tm_mon+1)*100 + tm.tm_mday;
	int todayTime = tm.tm_hour * 100 + tm.tm_min;
	
	int sumIncome,sumPeople = 0;
	
	printf("\n============================================================================================\n");
	printf("\n====================================== 발권을 종료합니다..==================================\n");
	printf("\n============================================================================================\n");
	printf("\n========================================= 발권  내역 =======================================\n");
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n","이용권 종류","이용 시간","발권 수량","우대 구분","나이","입장료 총액");
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s","(종합/파크)","(1Day/After4)","(매)","(1-6)","(세)","(원)");
	printf("\n============================================================================================\n");	
		
	for (int i = 0 ;i <= row ;i++){	
		for (int j = 0; j < 6; j++){
			printf("%-10d\t",reportArray[i][j]); //reportArray 000102030405/101112131415/...
		}
		printf("\n");
	}
	
	FILE *filepointer = fopen("report.csv","a");
		
	for (int i = 0 ;i <= row ;i++){
		fprintf(filepointer,"%d,%d,%d,%d,%d,%d,%d\n",todayDate,todayTime,reportArray[i][0],reportArray[i][1],reportArray[i][2],reportArray[i][3],reportArray[i][5]);
		sumPeople += reportArray[i][2];
		sumIncome += reportArray[i][5];
	}
		
	fprintf(filepointer,"%s,%s,%s,%s,%d,%s,%d\n","","","","1일 총 입장 인원",sumPeople,"1일 총 매출 액",sumIncome);
	
	printf("\n======================================= 1일 총 입장 인원: %d 명 / 총 매출 : %d 원 ======\n",sumPeople,sumIncome);
	printf("\n============================================================================================\n");
	printf("\n\t\t\t\t이용해주셔서 감사합니다!\n");
	printf("\n============================================================================================\n");
}

int main ()
{	
	do {
		
		startresetPart();

		questionPart();
		
		calculationPart();
		
		resultPart();
		
	} while (contiChoice == 1);
	
	endsystemPart();
	
	return 0;
}
