#include <stdio.h>

// function def
char * checker(int age);
void testResult(int score);
float ratioOfSuccessfulCandidate(float totalNumberOfCandidate, int scoreOfCandidate[]);


int main(){
    /*
     *  question:
     *  大人と子供を判別したい。
     *  char[] checker(int age); を実装し、20才以上であれば adult と、そうでなければ children と標準出力に表示せよ。
     *
     *  tips:
     *  文字列を返すときは、pointerを返してあげるのが良い。(文字列自体を返すことはできない。)
     */

    // test
    printf("-------- question1 --------\n");
    printf("checker(21) == %s(expected adult)\n", checker(21));
    printf("checker(3) == %s(expected children)\n", checker(3));
    printf("---------------------------\n\n");

    /*
     *  question:
     *  試験の結果を判定したい。
     *  60点以下 -> 不可
     *  60 - 70 -> 可
     *  70 - 80 -> 良
     *  80 - 100 -> 優
     *
     *  void testResults(int score);
     */

    // test
    printf("-------- question2 --------\n");
    printf("testResults(60) expected 不可\n result -> ");
    testResult(60);
    printf("testResults(90) expected 優\n result -> ");
    testResult(90);
    printf("---------------------------\n\n");

    /*
     * question:
     * 人数とそれぞれの点数を入力して、60点以上の者の割合を表示する。
     */

    //test
    printf("-------- question3 --------\n");
    printf("int scores[] = {100, 80, 40, 50}\n");
    int scores[] = {100, 80, 40, 50};
    printf("ratioOfSuccessfulCandidate(4, scores) expected 0.5\n result -> %0.1f\n", ratioOfSuccessfulCandidate(4, scores));
    printf("---------------------------\n\n");

}


// -------------  write your function bellow -------------------

char * checker(int age){
    char *result[10];
    *result = age >= 20 ? "adult" : "children";
    return *result;
}

void testResult(int score){
    if (score > 80){
        printf("優\n");
    }else if(score > 70){
        printf("良\n");
    }else if(score > 60){
        printf("可\n");
    }else{
        printf("不可\n");
    }
}

float ratioOfSuccessfulCandidate(float totalNumberOfCandidate, int scoreOfCandidate[]){

    // variables
    float counter = 0;
    int i = 0;
    float ratio;

    for(i=0; i<totalNumberOfCandidate; i++) {
        if (scoreOfCandidate[i] > 60) {
            counter++;
        }
    }
    ratio = counter / totalNumberOfCandidate;
    return ratio;
}

// -------------------------------------------------------------