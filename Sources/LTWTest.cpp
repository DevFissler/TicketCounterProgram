#include <stdio.h>
int main ()
{
for (;;)
{
int ticketAuth,ticketTime,ticketQuan,idNumber,discountType,unitPrice;

const int ALL_ALL_ADULT = 59000; const int ALL_ALL_YOUTH = 52000; const int ALL_ALL_KIDS = 47000; const int ALL_ALL_BABY = 15000; // 3�� ~ 12 �� ��� , �� 13�� ~ �� 18�� û�ҳ�, �� 65�� �̻� ��̿�� 
const int ALL_AF4_ADULT = 48000; const int ALL_AF4_YOUTH = 42000; const int ALL_AF4_KIDS = 36000; const int ALL_AF4_BABY = 15000;
const int PARK_ALL_ADULT = 56000; const int PARK_ALL_YOUTH = 50000; const int PARK_ALL_KIDS = 46000; const int PARK_ALL_BABY = 15000;
const int PARK_AF4_ADULT = 45000; const int PARK_AF4_YOUTH = 40000; const int PARK_AF4_KIDS = 35000; const int PARK_AF4_BABY = 15000;

int totalPrice;
float discountRate;
printf("\n======Ƽ�� �߱� �ý���v3.16 Developed by DevFissler======\n\n");
printf("�̿���� ������ �����ϼ���.\n");
printf("%10s\t%10s\n", "1.���� �̿��", "2. ��ũ �̿��");
scanf("%d",&ticketAuth);

printf("\n������ �����ϼ���.\n");
printf("%10s\t%10s\n", "1.1Day ", "2. After4");
scanf("%d",&ticketTime);

if (ticketAuth <= 2 && ticketTime <= 2){ // 1,2 �̿��� ������ �� �� ���� x 
	
	printf("\n�ֹε�Ϲ�ȣ�� �� 6�ڸ���  �Է��ϼ���.\n");  //���̿� ���� ��� å�� �κ� 
	scanf("%d",&idNumber);
	
	int birthYear,birthDate,fullAge;
	const int nowYear = 2022, preDate = 316;  //���� ��, ���� �� 
		
	
	if (idNumber/10000 < 22){  // ��� �⵵ ��� 
	 birthYear = 2000+ idNumber/10000;
	 }
	else{
	 birthYear = 1900+ idNumber/10000;
	 }
	
	birthDate = idNumber%10000;  //����� ��� 
	
	if (birthDate<=1231){

	if ( birthDate <= preDate) { //���� ���� 
	 fullAge=nowYear-birthYear;
	 }
	else if (birthDate > preDate) {
	 fullAge=nowYear-birthYear-1;
	}
	
	if (ticketAuth ==1){
	 if (ticketTime ==1){
	  	if(fullAge>=19 && fullAge<65){
			unitPrice=ALL_ALL_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=ALL_ALL_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=ALL_ALL_KIDS;
			}
		else {
			unitPrice=ALL_ALL_BABY;
			}
		}
	 else if (ticketTime ==2){
		if(fullAge>=19 && fullAge<65){
			unitPrice=ALL_AF4_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=ALL_AF4_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=ALL_AF4_KIDS;
			}
		else {
			unitPrice=ALL_AF4_BABY;
			}
		}
	}
	else if (ticketAuth ==2){
	 if (ticketTime ==1){
	  	if(fullAge>=19 && fullAge<65){
			unitPrice=PARK_ALL_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=PARK_ALL_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=PARK_ALL_KIDS;
			}
		else {
			unitPrice=PARK_ALL_BABY;
			}
		}
	 else if (ticketTime ==2){
		if(fullAge>=19 && fullAge<65){
			unitPrice=PARK_AF4_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=PARK_AF4_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=PARK_AF4_KIDS;
			}
		else {
			unitPrice=PARK_AF4_BABY;
			}
		}
	}
	

printf("\n�߱���  Ƽ��  ���� �Է��ϼ���:   ");
scanf("%d",&ticketQuan);

printf("\n�������� �����ϼ���.\n");
printf("1. ����(��� ���� �ڵ�ó��)\n");
printf("2. �����\n"); //���� 1�� 50% 
printf("3. ����������\n"); //���� 1�� 50% 
printf("4. �ް� �庴\n"); // ���ո� ���� 1�� 49% 
printf("5. �ӻ��\n");  // ���ո� ���θ� 50% 
printf("6. �ٵ��� �ູī��\n"); // ���� ���� 30% 
scanf("%d",&discountType);

	switch (discountType){
		case (1) : 
		discountRate = 0;
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

if (ticketQuan ==1){
totalPrice=unitPrice*(1-discountRate);
}
else {
totalPrice=(unitPrice*ticketQuan)-(unitPrice*discountRate)*2;
}

printf("%f\n",discountRate);
printf("\n�� %d �� �߱�, ������ %d �� �Դϴ�\n\n",ticketQuan,totalPrice);
printf("�����մϴ�.\n"); 
} //birthday ���� �� return 
} //���� ���� ���� �� return 
} //�ݺ� �Է� ������ ���� ���� 
return 0;
}
