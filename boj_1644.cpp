#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 400

using namespace std;

int N;
vector<bool> prime;

void check_num(int n)
{
	prime[1] = false;
	
	for (int i = 2; i <= n; i++) {
		int idx = 2;

		while (idx * idx <= i) {
			if (i % idx == 0) {
				prime[i] = false;
				break;
			}
			idx++;
		}
	}
}

int main()
{
	scanf("%d", &N);

	prime.resize(N + 1, true);
	check_num(N);

	int answer = 0;

	for (int i = 2; i <= N; i++) {
		int sum = 0;
		if (!prime[i]) continue;

		for (int j = i; j <= N; j++) {
			if (prime[j]) sum += j;

			if (sum > N) break;
			else if (sum == N) {
				answer++;
				break;
			}
		}
	}

	printf("%d", answer);

	return 0;
}

/*

소수 수열이 필요함
1. 에라토스테네스의 체를 통해 수열을 구하면 시간초과, O(400만^2)
2. 1부터 400만까지 소수 판별법을 통해서 확인, O(N * N^(1/2))
	소수 판별법 : 약수의 절반 이하까지만 확인, O(N^(1/2))
	https://curt-park.github.io/2018-09-17/algorithm-primality-test/

3. 12ms 코드(내 코드는 1.4s)
	https://www.acmicpc.net/source/32624041

*/