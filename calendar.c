
#include <stdio.h>

int youbi(int,int);/* �j���v�Z�֐��̃v���g�^�C�v�錾 */
int uruu(int);/* ���邤�N����֐��̃v���g�^�C�v�錾 */

void main(void){

	int year, month, weekday, day, c, wd;
	int last[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	year = 0;
	month = 0;
	weekday = 0;
	
	do {

	printf("�������J�����_�[�̐������͂��Ă�������\n");
	printf("���� =>");
	scanf("%d",&year);

	}while(year <= 1000 || year >= 9999); /* �_���G���[�͂��� */

	do{

	printf("������͂��Ă�������\n");
	printf("�� =>");
	scanf("%d",&month);

	}while(month < 1 || month > 12); /* �_���G���[�͂��� */
	
	weekday = youbi(year,month); 
	
	c = uruu(year);
	if( c = 1 ){
		last[1]+=1;
	}


	printf("-------%d�N-------\n"
		"--------%02d��--------\n"
		"�� �� �� �� �� �� �y\n",year,month);
	
	for( c = 0 ; c < weekday ; c++){ /* ���r���[�ȗj���̏ꍇ1���܂ŃX�y�[�X�Ŗ��߂� */

	printf("   ");

	}

	for(day = 1, wd = weekday ; day <= last[month-1] ; day++, wd++){

		printf("%02d ",day);

		if ((wd+1)%7 == 0){  /* �y�j���ŉ��s */

		printf("\n");

		}

	}

}

/* �e���P���̗j�������߂�֐� */

int youbi(int year,int month){
	
	int x = 0, y = 0, youbi = 0;
	x = (year / 4) + year;
	x -= year / 100;
	x += year / 400;
	y = ((month * 13) + 8) / 5;
	youbi = (x + y + 1) % 7;
	
	return youbi;

}

/* ���邤�N����֐� */
int uruu(int nen){

	if(nen % 400 == 0 || (nen % 4 == 0 && nen % 100 != 0)){
   
	return 1;/* ���邤�N�Ȃ�߂�l1 */

	}else{

	return 0;/* ���N�Ȃ�߂�l0 */

 	}

}
