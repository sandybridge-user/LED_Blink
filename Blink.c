/*
* About this program: 
* File name: Blink.c
* For Arduino Uno
* 
* Blink.ino���쐬
*			��
* �_�ł�����LED�̌����w�� 
*			��
* �}�C�R����PIN�ԍ����w��~LED�̌���
*			��
* Blink.ino�ɏ�������
*
* �ϐ��ꗗ�F
* led (int)�F�ڑ�����LED�̌�����͂����Ă���B
* i (int)�Fi+1���(�����l�Fi=0)�ɕ\��������LED��PIN�ԍ�������
* pin (int): �_��������LED��PIN�ԍ�������B���[�v���Ŏg���܂킵�Ă���B
* 
*/

#include <stdio.h>

int main(void) {

	//Blink.ino���쐬
	FILE* fp;
	fp = fopen("Blink.ino", "w"); //Blink.ino���������݃��[�hw�ŊJ���B
	fprintf(fp, "void setup() {\n");
	fclose(fp);


	printf("���̃v���O������Arduino Uno���͂��̌݊��{�[�h�p�ł��B���̃{�[�h�ɂ͎g���܂���B\n");

	//LED�̌�������
	printf("�_�ł�����LED�̌�(���R��)����͂��āAEnter�L�[�������Ă��������B\n");
	int led = 0;
	scanf("%d", &led);
	printf("���͂��ꂽ��:%d \n", led);


	//�ڑ�����PIN������
	for (int i = 0 ; i < led; i++) {
		printf("�ڑ�����s���ԍ�(���R��)����͂��Ă��������B\n");
		int pin_num = 0;
		scanf("%d", &pin_num);
		fp = fopen("Blink.ino", "a"); //�ǉ��������ݐ�p�ŊJ��
		fprintf(fp, "pinMode(%d, OUTPUT);\n", pin_num);
		//fclose(fp);
		printf("�ڑ�����s���F%d ��OUTPUT�ɐݒ�\n" ,pin_num);
	}

	fp = fopen("Blink.ino", "a"); //�ǉ��������ݐ�p�ŊJ��
	fprintf(fp, "}\n");
	fprintf(fp, "void loop(){\n");
	fclose(fp);

	
	//LED��_�ł����鏇�Ԃ�����
	printf("\n");
	printf("LED��ڑ�����s�������߂܂��傤�B\n");

	for (int i = 0; i < led; i++) {
		//����
		printf("%d��ڂɓ_��������LED��PIN�ԍ�����͂��Ă��������B\n", i + 1);
		int pin = 0;
		scanf("%d", pin);
		printf("%d�Ԃ�_�������܂��B\n", pin);
		
		printf("\n");
		printf("���~���b�_�������܂����H\n");
		int wait_t = 0;
		scanf("%d", wait_t);
		printf("%d�~���b�ԓ_��\n", wait_t);

		//��������
		fp = fopen("Blink.ino", "a"); //�ǉ��������ݐ�p�ŊJ��
		fprintf(fp, "digitalWrite(%d, HIGH);\n", pin);
		fprintf(fp, "delay(%d)\n" , wait_t);
		fprintf(fp, "digitalWrite(%d, LOW);\n", pin);
		fclose(fp);
	
		}
	
	fp = fopen("Blink.ino", "a"); //�ǉ��������ݐ�p�ŊJ��
	fprintf(fp, "}\n");
	fclose(fp);

	printf("����͈ȏ�ł��B\n");
	

	return 0;
}