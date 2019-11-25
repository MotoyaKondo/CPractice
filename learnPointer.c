#include <stdio.h>

// initialized functions
int checkMemoryNumber(void);
int tryPointer(void);
int arrayPointer(void);

// main function
int main(void){
    /*
     * Pointer に関する参考
     *
     * 工学院大学 非情報学生のための C/C++ 入門
     * https://brain.cc.kogakuin.ac.jp/~kanamaru/lecture/prog1/index.html
     *
     * メモリとアドレス / 配列と関数を用いた際のメモリ配置 / アドレスとポインタ / 配列とポインタ
     */
    checkMemoryNumber();
    tryPointer();
    arrayPointer();
    return 0;
}

// functions
int checkMemoryNumber(void){

    int x, y, i;
    int a[5];

    x = 2;
    x = 5;
    for (i=0;i<5;i++){
        a[i] = i;
    }
    /* アドレス番号
     *
     * 変数 ->
     * 変数については random にアドレスが割当られる。
     *
     * 配列　->
     * 同じ配列については、連番でアドレスが配置される。
     * (32bitプログラムなら、1メモリは 4byte なのでアドレス4つ分である。)
     */
    printf("x のアドレス番号は: %p\n", &x);
    printf("y のアドレス番号は: %p\n", &y);
    printf("a(array) のアドレス番号は、\n");
    for (i=0;i<5;i++){
        printf("%d: %p\n", i+1, &a[i]);
    }

    return 0;
}

int tryPointer(void){
    int x;
    int *p;

    // 初期化のみだと、random に数値が割り振られいている。
    printf("x is %d\n", x);
    x = 20;
    printf("x is changed to %d\n", x);

    /* null pointer について
     *
     * pointer を初期化せずに値の再代入を試みるとうまくいかない。
     * -> Pointer のアドレスを NULL に変更する。
     * http://www.kouno.jp/home/c_faq/c5.html
     *
     * *p = 10;
     * というように、Pointer が定まっていない状態で代入しようとすると Error になる。
     * -> [1]    39394 segmentation fault  ./a.out
     * これを解消するためは、初期化された Pointer には、現段階で利用されているアドレスを渡してあげる必要がある。
     */
    // アドレスを渡す。
    p = &x;
    printf("*p = %d\np = %p\n", *p, p);

    return 0;
}

int arrayPointer(void){
    int * p;
    int array[5] = {100, 200, 300, 400, 500};
    int sum=0, i;

    // 配列の最初の pointer をいれる。
    p = &array[0];

    for(i=0;i<5;i++){
        *p += array[i];
        printf("current add: %p -> next add: ", p);
        // address をインクリメント(1を足しているように見えるが実際は次のメモリの番号に移動している(4bit分移動している。))
        p++;
        printf("%p\n", p);
    }

    return 0;
}