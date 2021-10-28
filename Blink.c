/*
* About this program: 
* File name: Blink.c
* For Arduino Uno
* 
* Blink.inoを作成
*			↓
* 点滅させるLEDの個数を指定 
*			↓
* マイコンのPIN番号を指定×LEDの個数分
*			↓
* Blink.inoに書き込む
*
* 変数一覧：
* led (int)：接続するLEDの個数を入力させている。
* i (int)：i+1回目(初期値：i=0)に表示させるLEDのPIN番号を質問
* pin (int): 点灯させるLEDのPIN番号を質問。ループ内で使いまわしている。
* 
*/

#include <stdio.h>
int led = 0;
int pin = 0;
int pin_num = 0;
int i = 0;

int main(void) {

	//Blink.inoを作成
	FILE *fp;
	fp = fopen("Blink.ino", "a"); //Blink.inoを書き込みモードaで開く。
		//void setup(){ を入力
		fprintf(fp, "void setup() {\n");
		fprintf(fp, "//以下が接続するピンの設定です。\n");


	printf("このプログラムはArduino Uno又はその互換ボード用です。他のボードには使えません。\n");

	//LEDの個数を質問
	printf("点滅させるLEDの個数(自然数)を入力して、Enterキーを押してください。\n");
	scanf("%d", &led);
	printf("入力された個数:%d \n", led);
	printf("\n");

       
	//接続するPINを質問
	while (i < led) {
		printf("接続するピン番号(自然数)を入力してください。\n");
		scanf("%d", &pin_num);
		
		fprintf(fp, "pinMode(%d, OUTPUT);\n", pin_num);
		printf("接続するピン：%d をOUTPUTに設定\n" ,pin_num);
		printf("\n");
		i++;
	}

	fprintf(fp, "}\n");
	fprintf(fp, "\n");
	fprintf(fp, "void loop(){\n");
	
	//LEDを点滅させる順番を質問
	printf("\n");
	printf("LEDを接続するピンを決めましょう。\n");

	i = 0;

	while (i < led) {
		//点灯させる順番を質問
		printf("%d回目に点灯させるLEDのPIN番号を入力してください。\n", i + 1);
		scanf("%d", &pin);
		printf("%d番を点灯させます。\n", pin);
		
		printf("\n");
		printf("何ミリ秒点灯させますか？\n");
		int wait_t = 0;
		scanf("%d", &wait_t);
		printf("%dミリ秒間点灯\n", wait_t);
		printf("\n");

		//書き込み
		fprintf(fp, "digitalWrite(%d, HIGH);\n", pin);
		fprintf(fp, "delay(%d);\n" , wait_t);
		fprintf(fp, "digitalWrite(%d, LOW);\n", pin);
		fprintf(fp, "\n");
		i++;
	
		}
	
	fprintf(fp, "}\n");
	fclose(fp);

	printf("質問は以上です。\n");
	printf("プログラムが出来上がりました。\n");
	

	return 0;
}
