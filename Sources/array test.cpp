#include <stdio.h>
int main ()
{
int i=0;
int row=0; 
int report[50][3] ={0};
int contiAsk;
int sum =0;
for (;;){ 
	
	int input1,input2,input3;
	
	printf("입력 연습 1 :");
	scanf("%d",&input1); 
	report[row][0] = input1;
	
	printf("입력 연습 2 :");
	scanf("%d",&input2); 
	report[row][1] = input2;
	
	printf("입력 연습 3 :");
	scanf("%d",&input3); 
	report[row][2] = input3;
	
	printf("종료?: 1. 계속 2. 종료");
	scanf("%d",&contiAsk);
	
	if (contiAsk == 2)	{
	break;
	}
	
	else  {
	row++;
	}
}

for (int i=row-1;i==0;i--){	
	for (int j=0;j<3;j++){
		printf("%d\t",report[i][j]);
	}
	printf("\n");
}

for (int i=0;i<=2;i++){
	sum += report[i][2];
}

printf("%d",sum);

return 0;
}
