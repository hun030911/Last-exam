#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
int main() {
    int num[6]; // 이번주 로또 번호 랜덤 배정
    int i, j, a, b, c, d, e; // i,j = for 문 - a,b,c = 사용할 금액, 가진 기회, 거스름돈 - d = 오름차순으로 정렬할때 필요한것 - e = 입력한 번호 오름차순 정렬
    int count = 1; // 얻은 기회를 카운트 할것
    int rottonum[6]; // 수동으로 직접 입력해서 맞춰보는 번호
    int correct; // 맞춘 번호 갯수
    int check; // 중복을 찾기 위한것

    srand((unsigned)time(NULL)); // 로또 랜덤 번호 배정
    for (i = 0; i < 6; i++) {
        check = (rand() % 45) + 1;
        num[i] = check;
        for (j = 0; j < i; j++)
            if (check == num[j] && i != j) // 중복 찾기
                i--;
    }
    for (i = 0; i < 6; i++) { // 오름차순으로 정렬
        for (j = i; j < 6; j++) {
            if (num[i] > num[j]) {
                d = num[i];
                num[i] = num[j];
                num[j] = d;
            }
        }
    }
    printf("금액을 입력하시오 : "); // 사용할 금액
    scanf("%d", &a);
    if (a < 1000) { // 1000원 = 1회 최소 금액
        printf("최소 금액은 1000원 입니다.");
    }
    else { // 로또 수동으로 맞추기
        b = a / 1000; // 기회
        c = a % 1000; // 거스름돈
        printf("%d원이므로 %d번의 기회가 주어집니다. 거스름돈은 %d원 입니다.\n", a, b, c);
        for (i = 0; i <= a; i++) {

            printf("[%d회]\n", count); // 기회 카운트

            printf("1부터 45까지의 숫자를 6개 입력 : ");

            scanf("%d %d %d %d %d %d", &rottonum[0], &rottonum[1], &rottonum[2], &rottonum[3], &rottonum[4], &rottonum[5]); // 6개 번호 수동 입력

            for (i = 0; i < 6; i++) { // 오름차순으로 정렬
                for (j = i; j < 6; j++) {
                    if (rottonum[i] > rottonum[j]) {
                        e = rottonum[i];
                        rottonum[i] = rottonum[j];
                        rottonum[j] = e;
                    }
                }
            }
            printf("당신이 입력한 번호 : %d %d %d %d %d %d\n", rottonum[0], rottonum[1], rottonum[2], rottonum[3], rottonum[4], rottonum[5]);

            correct = 0; // 맞춘 번호 갯수

            for (i = 0; i < 6; i++) {
                for (j = 0; j < 6; j++) {
                    if (num[i] == rottonum[j]) { // 랜덤 배정된 번호와 입력한 번호가 같은지 확인                       
                        correct++;
                        break;
                    }
                }
            }
            printf("맞춘 번호의 갯수 : %d\n\n", correct); // 비교한 뒤 결과

            if (correct == 6) { // 다 맞췄다면 1등
                printf("1등 상금 축하드립니다.");
                break;
            }

            else if (count == b) { // 마지막 기회까지 틀렸다면 이번 주 랜덤 번호 출력
                printf("다음 기회를 노리세요.\n");
                printf("이번주 로또 번호는 : ");
                for (i = 0; i < 6; i++) {
                    printf("%d ", num[i]);
                }
                printf("입니다.");
                break;
            }
            count++; // 기회 카운트
        }
    }
    return 0;
}