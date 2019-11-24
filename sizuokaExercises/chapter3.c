#include <stdio.h>

// Mention Definition of Functions
int integerAndFloat();
int scanUsage(int * number);
int forArithmeticOperation(int * number, int ** result[]);


// Main Function
int main(void){

    // variables
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
     * int forArithmeticOperation(int * number);
     *
     * 概要:
     * 引数の(int * a) では、aはアドレスを指している。
     * int * a; と初期化したら a を渡せば良いし、int a なら &a を渡せば良い。
     *
     */
//    printf("--------------- question3 ----------------\n");
//    *number = 10;
//
//    int ** result[4];
//    int i;
//    char operands[4] = {'+', '-', '*', '/'};
//
//    forArithmeticOperation(number, result);
//
//    for (i=0;i<4;i++){
//        printf("result %d %c 5 = %d", *number, operands[i], **result[i]);
//    }
//    printf("------------------------------------------\n\n\n");



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

//int forArithmeticOperation(int * number, int ** result[]){
//
//    int baseNumber = 5;
//
//    **result[0] = *number + baseNumber;
//    **result[1] = *number - baseNumber;
//    **result[2] = *number * baseNumber;
//    **result[3] = *number / baseNumber;
//
//    return 0;
//}