#include <stdio.h>

// initialize function
int introOfPointer(void);
int trail1(void);
int introOfConditionOperator(void);

// main function
int main(void){
//    introOfPointer();
//    trail1();
    introOfConditionOperator();
}

// function def
int introOfPointer(void){
    /* --------------- #1. アドレスの割り当てについて ----------------
     * int a, b;
     * とするとこの場合 a は random に割り当てられる。
     * 次に int 型であるので、b は 4bit 進んだ &a - 4bit に割り当てられる。
     *
     * double a, b;
     * の場合には、8bit(int の double) 分の領域が確保されるので、
     * アドレス b のアドレスは &a - 8bit である。
     *
     */
    int a, b, *ap, *bp;

    ap = &a;
    bp = &b;

    scanf("%d %d", ap, bp);
    printf("%d, %d\n", a, b);

    *ap = 4;
    *bp = 6;
    printf("%d, %d\n", a, b);
    printf("アドレス a = %p, b = %p\n", ap, bp);
    /* --------------- #2. アドレスのインクリメントについて ----------------
     *
     * アドレスをインクリメントすると、確保されていない次のアドレスをさす。
     * すなわち int 型で領域を取得し、increment すると 4bit 先をさし、
     * double 型でメモリ領域を取得し、increment すると 8bit 先をさす。
     */
    bp++;
    printf("アドレス a = %p, b = %p\n", ap, bp);

    /* --------------- #3. [復習] アドレス演算子 と ポインタ演算子 ----------------
     *
     * "*" は pointer operator で pointer to type という性質を持つ。
     * すなわち pointer の先にある型のリテラル情報を取得するという意味である。
     *
     * "&" は address operator で アドレスを取得する。
     *
     * これらは右側から計算されるので、
     * a と *&a は同じ意味である。
     */
    printf("%d %d\n", *(&a) * *(&b), (*ap) + (*bp));

    return 0;
}


int trail1(void){
    /* introOfPointer() の内容について、double 型でも試してみる。
     * 確かに、8 bit 先のアドレスを指していることがわかる。
     */
    double a, b, *ap, *bp;

    ap = &a;
    bp = &b;

    scanf("%lf %lf", ap, bp);
    printf("%5.1f, %5.1f\n", a, b);

    *ap = 3.6;
    *bp = 3.8;
    printf("%5.1f, %5.1f\n", a, b);
    printf("アドレス a = %p, b = %p\n", ap, bp);
    bp++;
    printf("アドレス a = %p, b = %p\n", ap, bp);

    printf("%5.1f %5.1f\n", *(&a) * *(&b), (*ap) + (*bp));

    return 0;
}

int introOfConditionOperator(void){
    int results[8],
        i;

    int a = -10,
        b = 1,
        x = -7;

    /* --------------- #4. 演算子 ----------------
     * 演算子 operand には、優先順位と結合規則がある。
     *
     * 優先順位 1つの命令に operand が複数あったときに、どの operand の演算を優先するか
     * 結合規則 1つの命令に同じ operand があったとき、右から計算するか 左から計算するか
     *
     * 参考 https://www.grapecity.com/developer/support/powernews/column/clang/020/page05.htm
     */
    results[0] = a < x;
    results[1] = !(a < x);
    results[2] = !!(a < x);
    results[3] = a == b;
    // b=0 なら左から結合するので、trueになる。　
    results[4] = a == b == b;
    results[5] = a < x < b;
    results[6] = (a < x) && (x < b);
    results[7] = !(a >= x) || !(x >= b);

    for(i=0;i<8;i++){
        printf("result %d is %d\n", i, results[i]);
    }

    return 0;
}