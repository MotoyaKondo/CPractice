#include <stdio.h>

// Mention Definition of Functions
int integerAndFloat();
int scanUsage(int * number);
int forArithmeticOperation(int number1, int number2);
float getTrapezoidArea(int up, int bottom, int height);
int divideNumber(int number);

// Main Function
int main(void){

    // variables
    int i;
    int * number;

    /*
     * Qsuestion1:
     * integer と float について
     *
     * 概要:
     * (type) operator でキャストできる。
     * また、() で演算の優先度を変更することができる。
     * (double) 4 / 5 だと、 (double) 4 / (double) 5 に変換され、0.8になる。
     * 一方で、(double) (4 / 5) は 4 / 5 について計算された結果 0 が double に変換される。そのため 0.0 になる。
     */
    printf("--------------- question1 ----------------\n");
    integerAndFloat();
    printf("------------------------------------------\n\n\n");

    /*
     * Question2:
     * scanf による入力
     *
     * 概要:
     * scnaf("%d", &a);
     * では、%dという format に適応する入力を &a のアドレスに挿入される。
     * format に適応しない場合は、何も入力されない。
     */
    printf("--------------- question2 ----------------\n");
    printf("number: %d\n", *number);
    scanUsage(number);
    printf("変更された number: %d\n", *number);
    printf("------------------------------------------\n\n\n");


    /*
     * Question3:
      * 四則演算を計算するプログラム
     * int forArithmeticOperation(int number1, int number2, int * ans);
     *
     * 概要:
     * 引数の(int * a) では、aはアドレスを指している。
     * int * a; と初期化したら a を渡せば良いし、int a なら &a を渡せば良い。
     */
    printf("--------------- question3 ----------------\n");
    forArithmeticOperation(1, 2);
    printf("------------------------------------------\n\n\n");

    /* Question4:
     * 上底、下底、高さ を入力として与え、台形の面積を求める関数を作成せよ。
     * float getTrapezoidArea(int up, int bottom, int height);
     */
    printf("--------------- question4 ----------------\n");
    float area = getTrapezoidArea(2, 3, 7);
    printf("trapezoid area is %0.1f\n", area);
    printf("------------------------------------------\n\n\n");

    /* Question5:
     *  5 桁の整数（最初の数字は必ず 0 でない）を入力するものとする．
     *  それを各桁毎に分解し，間に 1 つ以上の空白をあけて出力し，
     *  次の行に，各桁の数字を逆順に 1 つ以上の空白をあけて出力するプログラムを書け．
     * int divideNumber(int number);
     */
    printf("--------------- question5 ----------------\n");
    *number = 54321;
    divideNumber(*number);
    printf("------------------------------------------\n\n\n");

    return 0;
}

// Functions
int integerAndFloat(){
    /*
     * (type) operand
     * で operand を type に変換することができる。
     *
     * operand operator (operand operator operand) で () の演算を優先することができる。
     */

    printf("4.0 / 5.0 = %0.1f\n", 4.0 / 5.0);
    printf("(int) (4.0 / 5.0) = %d\n", (int) (4.0 / 5.0));
    printf("4 / 5 = %d\n", 4/5);
    printf("(20 / 5) * (19 / 4) = %d\n", (20 / 5) * (19 / 4));
    printf("(double) 4 / 5 = %0.1f\n", (double) 4 / 5);
    printf("(20.0 / 5.0) * (19.0 / 4.0) = %0.1lf\n", (20.0 / 5.0) * (19.0 / 4.0));
    printf("(double) (4 / 5) = %0.1lf\n", (double) (4 / 5));
    return 0;
}

int scanUsage(int * number){
    printf("int型の数値を入力してください。");
    scanf("%d", number);
    return 0;
}

int forArithmeticOperation(int number1, int number2){
    printf("%d + %d = %d\n", number1, number2, number1+number2);
    printf("%d - %d = %d\n", number1, number2, number1-number2);
    printf("%d * %d = %d\n", number1, number2, number1*number2);
    printf("%d / %d = %d\n", number1, number2, number1/number2);
    return 0;
}

float getTrapezoidArea(int up, int bottom, int height){
    return  ((float) up + bottom) * (float) height / 2.0;
}

int divideNumber(int number){

    int digits[5], i;

    digits[0] = number / 10000;
    digits[1] = (number % 10000) / 1000;
    digits[2] = (number % 1000) / 100;
    digits[3] = (number % 100) / 10;
    digits[4] = (number % 10);

    printf("divide number is ");
    for(i=0;i<4;i++){
        printf("%d ", digits[i]);
    }
    printf("%d\n", digits[4]);

    printf("reversed it");
    for(i=4;i>0;i--){
        printf("%d ", digits[i]);
    }
    printf("%d\n", digits[0]);

    return 0;
}