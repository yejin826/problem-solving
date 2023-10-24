// 소프티어 자동차 테스트
// 반복문만 돌렸을 시 O(100억)으로 시간초과
// 이분탐색 : 이분탐색을 이용하면 O(log100억) safe
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, q;
vector<int> car;
vector<int> query;

int main(int argc, char** argv)
{
	scanf("%d %d", &n, &q);

	car.resize(n + 1);
	query.resize(q + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &car[i]); // 인덱스 1부터 n까지
	}

	sort(car.begin(), car.end());

	for (int i = 1; i <= q; i++) {
		scanf("%d", &query[i]);
	}

	for (int i = 1; i <= q; i++) {
		int left = 1;
		int right = n;
		int mid = (left + right) / 2;
		bool check = true;

		while (left <= right) {
			mid = (left + right) / 2;

			if (car[mid] == query[i]) {
				printf("%d\n", (mid - 1) * (n - mid));
				check = false;
				break;
			}
			else if (car[mid] < query[i]) {
				left = mid + 1;
			}
			else if (car[mid] > query[i]) {
				right = mid - 1;
			}
		}

		if (check) printf("0\n");
	}

	return 0;
}

/*


1차 시도에서 틀린 이유
	cin, cout 사용으로 시간 초과 -> scanf, printf로 변경
	이분탐색 while문의 조건을 잘못 설정 -> while (left <= right)로 수정

접근
단순 반복문으로 원리와 계산식 정리 -> 시간복잡도 계산
	-> 시간 복잡도 최적화 알고리즘 -> 세그먼트 트리(x) -> 이분탐색(o)


*/