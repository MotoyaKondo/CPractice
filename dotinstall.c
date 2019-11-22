#include <stdio.h>

// prototype mention
void sayHello(void);
int sayHi(void);
int variablesList(void);
int operatorList(void);
int conditionIfUsage(void);
int conditionSwitchUsage(void);
int loopWhileUsage(void);
int loopForUsage(void);
float getMax(float a, float b);
int getMinWithTernaryOperator(int a, int b);
int variableScope(int n);
int arrayUsage(void);
int pointerUsage(void);

// global variables
int globalVariable = 777;

// main function
int main(void){
//    sayHello();
//    sayHi();
//    variablesList();
//    operatorList();
//    conditionIfUsage();
//    conditionSwitchUsage();
//    loopWhileUsage();
//    loopForUsage();
//    printf("max(0.1,0.7) -> %0.1f\n", getMax(0.1, 1.7));
//    printf("min(1, 3) -> %d\n", getMinWithTernaryOperator(1, 3));
//    variableScope(1);
//    variableScope(2);
//    variableScope(3);
//    arrayUsage();
    pointerUsage();
}

// functions
void sayHello(void){
    /*
     * 複数行のコメント
     */
    //    一行のコメント
    printf("hello world\n");
}

int sayHi(void){
    printf("Hi!\n");
    // to make sure exit status is 0.
    return 0;
}

int variablesList(void){
    /*
     * 変数: 中身が変わる可能性(Mutable)がある箱のようなもの。C言語ではデータ型が決まっている。
     * データ型 (int, float, char)
     *
     * format 形式化する方法 について
     * データ型に対して対応(int, float, char) -> (%d, %f, %c)
     */

    // initialize
    int x = 10;
    float y = 0.5;
    char c = 'A';

    // print formatted string(have to match each type of variables)
    printf("x=%d, y=%f, c=%c\n", x, y, c);

    return 0;
}

int operatorList(void){
    /*
     * For arithmetic operation
     *
     * Addition +
     * Subtraction -
     * Multiplication *
     * Deviation /
     * Surplus %
     *
     * 代入演算子
     * +=
     * -=
     *
     * 単項演算子
     * ++ increment
     * -- decrement
     */

    // initialized
    int x;

    // calculate
    x = 5 + 3;
    printf("5+3=%d\n", x);
    x = 5 - 3;
    printf("5-3=%d\n", x);
    x = 5 * 3;
    printf("5*3=%d\n", x);
    x = 5 / 3; // 1 (answer is integer.)
    printf("5/3=%d\n", x);
    x = 5 % 3; // 2 (only for integer opeland)
    printf("3=%d(mod 5)\n", x);

    // 代入演算子

    return 0;
}

int conditionIfUsage(void){

    // score initialized;
    int score = 80;

    // condition
    if(score >= 60){
        printf("You can pass.\n");
    }else if(score >= 80){
        printf("Great!\n");
    }else if(score < 100 || score > 90){
        printf("Perfect!\n");
    }else{
        printf("Try it again...\n");
    }

    return 0;
}

int conditionSwitchUsage(void){
    int rank = 3;

    printf("Your level is ");
    switch (rank){
        case 0:
            printf("beginner");
            break;
        case 1:
        case 2:
            printf("Intermediate");
            break;
        case 3:
            printf("Pro\n");
            break;
        default:
            printf("undefined");
            break;
    }

    return 0;
}

int loopWhileUsage(void){

    // while
    int m = 20;
    while(m < 10){
        printf("m: %d\n", m);
        m++;
    }

    // do while (procedure once even if it is not true condition.)
    int n = 20;
    do{
        printf("n: %d\n", n);
        n ++;
    }while(n < 20);

    return 0;
}

int loopForUsage(void){

    // initialize iterator.
    int i = 0;
    // loop
    for (i=0; i<20; i++){
        printf("i=%d\n", i);
        if(i % 3 == 0){
            continue;
        }
        if(i % 17 == 0){
            break;
        }
    }

    return 0;
}

float getMax(float a, float b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int getMinWithTernaryOperator(int a, int b){
    return a < b ? a : b;
}

int variableScope(int n){

    // destroy memory each time
    int localVariable = 0;
    // remain into the memories
    static int staticLocalVariable = 0;

    printf("[call: %d ] ", n);
    printf("local: %d, global: %d, static: %d\n", localVariable, globalVariable, staticLocalVariable);
    localVariable ++;
    staticLocalVariable ++;
    globalVariable ++;

    return 0;
}

int arrayUsage(void){

    // mention a number of memories
    int sales[3];

    sales[0] = 200;
    sales[1] = 300;
    sales[2] = 400;

    // easy way
    // int sales2[] = {200, 400, 600}
    // [] -> [3]
    int sales2[5] = {200, 400, 600};
    // -> {200, 400, 600, 0, 0}

    printf("year 2: %d\n", sales[2]);

    return 0;
}

int stringArray(void){
    /*
     * 文字列: char型の配列( *終端は \0 になる。)
     *
     * char s[4] = {"a", "b", "c", "\0"};
     * same as
     * char s[] = "abc";
     */

    // char s[] = "hello";
    // NOTICE: single quotation -> char, double quotation -> string
    char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

    // in python( print("hello") )
    int i;
    for (i=0; i<6; i++){
        // printf() take string as an argument.
        printf("%c ", s[i]);
        if (i == 6){
            printf("\n");
        }
    }

    return 0;
}

int pointerUsage(void){
    /*
     * 間接演算子とアドレス演算子
     * https://docs.microsoft.com/ja-jp/cpp/c-language/indirection-and-address-of-operators?view=vs-2019
     *
     * '*' : 単項演算子 (pointer to type) ポインターを介して値に間接的にアクセスする。
     * オペランドはポインター型である必要がある。(結果はpointerが指す値になる。)
     *
     * '&' : アドレス演算子 (address of) アドレスを渡す。
     *
     * 関数についてもアドレスを渡すことができる。
     * int roundup( void );   Function declaration
     * int  *proundup  = roundup;
     * int  *pround  = &roundup;
     * assert( pround == proundup );
     *
     *
     * また関数の引数を pointer to type にすることで、メモリを節約することができる
     * (渡してきた値の引数をそのまま利用することができる。)
     */

    int a;
    a = 10;

    int * pa;
    // aのアドレスを渡す(値は渡していない)
    pa = &a;
    int x = *pa;

    // aの値を書き換える
    a = 20;

    // pointerで指し示された値を表示する
    // xは値を渡されているので20に変わらないが、pa はアドレスを参照しているので20になっている。
    printf("x=%d, pa=%d\n", x, *pa);

    return 0;
}