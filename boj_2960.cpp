#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, K;
int cnt_k;

int main()
{
	scanf("%d %d", &N, &K);

	vector<bool> v(N + 1, true); // index : 1 ~ N

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (v[j]) {
				v[j] = false;

				if (++cnt_k == K) {
					printf("%d", j);
					return 0;
				}
			}
		}
	}

	return 0;
}