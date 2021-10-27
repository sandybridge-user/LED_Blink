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

int main(void) {

	//Blink.inoを作成
	FILE* fp;
	fp = fopen("Blink.ino", "w"); //Blink.inoを書き込みモードwで開く。
	fprintf(fp, "void setup() {\n");
	fclose(fp);


	printf("このプログラムはArduino Uno又はその互換ボード用です。他のボードには使えません。\n");

	//LEDの個数を質問
	printf("点滅させるLEDの個数(自然数)を入力して、Enterキーを押してください。\n");
	int led = 0;
	scanf("%d", &led);
	printf("入力された個数:%d \n", led);


	//接続するPINを質問
	for (int i = 0 ; i < led; i++) {
		printf("接続するピン番号(自然数)を入力してください。\n");
		int pin_num = 0;
		scanf("%d", &pin_num);
		fp = fopen("Blink.ino", "a"); //追加書き込み専用で開く
		fprintf(fp, "pinMode(%d, OUTPUT);\n", pin_num);
		//fclose(fp);
		printf("接続するピン：%d をOUTPUTに設定\n" ,pin_num);
	}

	fp = fopen("Blink.ino", "a"); //追加書き込み専用で開く
	fprintf(fp, "}\n");
	fprintf(fp, "void loop(){\n");
	fclose(fp);

	
	//LEDを点滅させる順番を質問
	printf("\n");
	printf("LEDを接続するピンを決めましょう。\n");

	for (int i = 0; i < led; i++) {
		//質問
		printf("%d回目に点灯させるLEDのPIN番号を入力してください。\n", i + 1);
		int pin = 0;
		scanf("%d", pin);
		printf("%d番を点灯させます。\n", pin);
		
		printf("\n");
		printf("何ミリ秒点灯させますか？\n");
		int wait_t = 0;
		scanf("%d", wait_t);
		printf("%dミリ秒間点灯\n", wait_t);

		//書き込み
		fp = fopen("Blink.ino", "a"); //追加書き込み専用で開く
		fprintf(fp, "digitalWrite(%d, HIGH);\n", pin);
		fprintf(fp, "delay(%d)\n" , wait_t);
		fprintf(fp, "digitalWrite(%d, LOW);\n", pin);
		fclose(fp);
	
		}
	
	fp = fopen("Blink.ino", "a"); //追加書き込み専用で開く
	fprintf(fp, "}\n");
	fclose(fp);

	printf("質問は以上です。\n");
	

	return 0;
}