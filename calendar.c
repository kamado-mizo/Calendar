
#include <stdio.h>

int youbi(int,int);/* 曜日計算関数のプロトタイプ宣言 */
int uruu(int);/* うるう年判定関数のプロトタイプ宣言 */

void main(void){

	int year, month, weekday, day, c, wd;
	int last[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	year = 0;
	month = 0;
	weekday = 0;
	
	do {

	printf("見たいカレンダーの西暦を入力してください\n");
	printf("西暦 =>");
	scanf("%d",&year);

	}while(year <= 1000 || year >= 9999); /* 論理エラーはじき */

	do{

	printf("月を入力してください\n");
	printf("月 =>");
	scanf("%d",&month);

	}while(month < 1 || month > 12); /* 論理エラーはじき */
	
	weekday = youbi(year,month); 
	
	c = uruu(year);
	if( c = 1 ){
		last[1]+=1;
	}


	printf("-------%d年-------\n"
		"--------%02d月--------\n"
		"日 月 火 水 木 金 土\n",year,month);
	
	for( c = 0 ; c < weekday ; c++){ /* 中途半端な曜日の場合1日までスペースで埋める */

	printf("   ");

	}

	for(day = 1, wd = weekday ; day <= last[month-1] ; day++, wd++){

		printf("%02d ",day);

		if ((wd+1)%7 == 0){  /* 土曜日で改行 */

		printf("\n");

		}

	}

}

/* 各月１日の曜日を求める関数 */

int youbi(int year,int month){
	
	int x = 0, y = 0, youbi = 0;
	x = (year / 4) + year;
	x -= year / 100;
	x += year / 400;
	y = ((month * 13) + 8) / 5;
	youbi = (x + y + 1) % 7;
	
	return youbi;

}

/* うるう年判定関数 */
int uruu(int nen){

	if(nen % 400 == 0 || (nen % 4 == 0 && nen % 100 != 0)){
   
	return 1;/* うるう年なら戻り値1 */

	}else{

	return 0;/* 平年なら戻り値0 */

 	}

}
