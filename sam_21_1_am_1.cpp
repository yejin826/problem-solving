// 이 코드는 주어진 예제는 잘 돌아갔지만 히든 케이스에서 오류가 발생했던 코드
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 20
using namespace std;
int N; // 격자의 크기
int arr[MAX_N][MAX_N]; // 격자, 인덱스 0부터 시작
pair<int, int> d[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct student {
    int id;
    int n1;
    int n2;
    int n3;
    int n4;
    int x;
    int y;
};

student student_list[MAX_N * MAX_N];

void find_seat(int x)
{
    int id = student_list[x].id;
    int n1 = student_list[x].n1;
    int n2 = student_list[x].n2;
    int n3 = student_list[x].n3;
    int n4 = student_list[x].n4;

    int R = 0, C = 0, empty = 0, like = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) continue;

            int tmp_empty = 0;
            int tmp_like = 0;

            for (int k = 0; k < 4; k++) {
                if (0 <= i + d[k].first && i + d[k].first < N && 0 <= j + d[k].second && j + d[k].second < N) {
                    if (arr[i + d[k].first][j + d[k].second] == n1) tmp_like++;
                    else if (arr[i + d[k].first][j + d[k].second] == n2) tmp_like++;
                    else if (arr[i + d[k].first][j + d[k].second] == n3) tmp_like++;
                    else if (arr[i + d[k].first][j + d[k].second] == n4) tmp_like++;

                    if (arr[i + d[k].first][j + d[k].second] == 0) tmp_empty++;
                }
            }

            if (like > tmp_like) continue;
            else if (like < tmp_like) {
                R = i; C = j; like = tmp_like; empty = tmp_empty;
            }
            else {
                if (empty > tmp_empty) continue;
                else if (empty < tmp_empty) {
                    R = i; C = j; like = tmp_like; empty = tmp_empty;
                }
                else {
                    if (R < i) continue;
                    else if (i > R) {
                        R = i; C = j; like = tmp_like; empty = tmp_empty;
                    }
                    else {
                        if (C < j) continue;
                        else {
                            R = i; C = j; like = tmp_like; empty = tmp_empty;
                        }
                    }
                }
            }

        }
    }

    arr[R][C] = id;
    student_list[x].x = R;
    student_list[x].y = C;
}

int cal_score()
{
    int sum = 0;

    for (int i = 0; i < N * N; i++) {
        int cnt = 0;

        for (int j = 0; j < 4; j++) {
            if (arr[student_list[i].x + d[j].first][student_list[i].y + d[j].second] == student_list[i].n1) cnt++;
            else if (arr[student_list[i].x + d[j].first][student_list[i].y + d[j].second] == student_list[i].n2) cnt++;
            else if (arr[student_list[i].x + d[j].first][student_list[i].y + d[j].second] == student_list[i].n3) cnt++;
            else if (arr[student_list[i].x + d[j].first][student_list[i].y + d[j].second] == student_list[i].n4) cnt++;
        }

        if (cnt == 0) continue;
        else if (cnt == 1) sum += 1;
        else if (cnt == 2) sum += 10;
        else if (cnt == 3) sum += 100;
        else if (cnt == 4) sum += 1000;
    }

    return sum;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N * N; i++) {
        scanf("%d %d %d %d %d", &student_list[i].id, &student_list[i].n1, &student_list[i].n2, &student_list[i].n3, &student_list[i].n4);
        student_list[i].x = -1; student_list[i].y = -1;
    }

    for (int i = 0; i < N * N - 1; i++) {
        find_seat(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = student_list[N * N - 1].id;
                student_list[N * N - 1].x = i;
                student_list[N * N - 1].y = j;
            }
        }
    }

    printf("%d", cal_score());

    return 0;
}