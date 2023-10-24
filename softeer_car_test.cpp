// ����Ƽ�� �ڵ��� �׽�Ʈ
// �ݺ����� ������ �� O(100��)���� �ð��ʰ�
// �̺�Ž�� : �̺�Ž���� �̿��ϸ� O(log100��) safe
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
		scanf("%d", &car[i]); // �ε��� 1���� n����
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


1�� �õ����� Ʋ�� ����
	cin, cout ������� �ð� �ʰ� -> scanf, printf�� ����
	�̺�Ž�� while���� ������ �߸� ���� -> while (left <= right)�� ����

����
�ܼ� �ݺ������� ������ ���� ���� -> �ð����⵵ ���
	-> �ð� ���⵵ ����ȭ �˰��� -> ���׸�Ʈ Ʈ��(x) -> �̺�Ž��(o)


*/