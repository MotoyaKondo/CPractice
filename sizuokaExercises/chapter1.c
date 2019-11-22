#include <stdio.h>

/*
 * == n進数の変換 ==
 * 小数点付きのn進数の変換
 * https://mathwords.net/syosuu2sin
 *
 * 1) 0.25(10) -> 0.01(2)
 * 2) 0.34(10) -> 0.010101110000...
 *
 * == コンピュータにおける数の扱い ==
 * http://www.cc.kyoto-su.ac.jp/~kbys/kiso/number/negative.html
 * 1. 符号+絶対値方式 : 最上位bitを符号とする(0 が2通り存在)
 * 2. 下駄ばき表現 : ある数を足して、全ての数正にする
 * 3. 2の補数表現 : 100000000 - 1 = 11111111 を利用して、計算する。最上位bit以外で表すことができる数の絶対値分の表現ができる。
 * -> 8bitが -128 to 128 までのひとまとまりになり、1 Byte である。
 *
 * cf) 16進数 (4bit をひとまとまりで考える。)
 * 0001 -> 1
 * 0010 -> 2
 * 0011 -> 3
 * ...
 * 1010 -> a
 * 1011 -> b
 * 1100 -> c
 * ...
 * 1110 -> e
 * 1111 -> f
 *
 * == コンピュータにおける文字の扱い ==
 * 8bit (1byte) 分の(-128 to 128) の情報に文字(char)を対応させたものを,ASCIIという。
 * ASCIIコード表なるものが存在する。
 * https://ja.wikipedia.org/wiki/ASCII
 *
 * 'A' -> 41(16) -> 01000001(2)
 * 01111010(2) -> 7A(16) -> 'Z'
 *
 * というように、one hot の 8bit と文字が対応している。
 */

int main(void){
    printf("This is chapter 1\nYou can see contents at comments in this script.\nCommand 'less chapter1.c'\n");
    return 0;
}