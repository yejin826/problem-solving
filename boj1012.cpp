#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int T; // �׽�Ʈ ���̽�
int M, N, K; // M�� ��, N�� ��, K�� ���� ����
vector<pair<int, int>> v; // ���� ��ġ ����
bool arr[50][50]; // ���� ��
bool visited[50][50]; // �湮 Ȯ��
pair<int, int> d[4] = { {1,0},{0,1}, {-1, 0}, {0,-1} };

void BFS(int R, int C);

int main()
{
	scanf("%d", &T); // �׽�Ʈ ���̽� �Է�

	for (int tc = 1; tc <= T; tc++) {
		// ��, ��, ���� ���� �Է�
		scanf("%d %d %d", &M, &N, &K);

		// �����̳� �ʱ�ȭ
		v.resize(K);
		for (int i = 0; i < N; i++) {
			memset(arr[i], false, sizeof(arr[i]));
			memset(visited[i], false, sizeof(visited[i]));
		}

		// ���� ��ġ �Է�
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &v[i].second, &v[i].first);

			arr[v[i].first][v[i].second] = true;
		}

		int larva = 0; // �ֹ��� ���� ����

		// ���߹��� �湮�ϸ� Ȯ��
		for (int i = 0; i < K; i++) {
			int R = v[i].first;
			int C = v[i].second;

			if (visited[R][C]) continue;
			else {
				BFS(R, C);
				larva++;
			}
		}

		printf("%d\n", larva);
	}

	return 0;
}

void BFS(int R, int C) // �Ķ���ʹ� ������ ��ǥ
{
	queue<pair<int, int> > q;
	q.push({ R, C });

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		visited[nowx][nowy] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nowx + d[i].first;
			int nexty = nowy + d[i].second;

			if (nextx < 0 || N <= nextx || nexty < 0 || M <= nexty) continue;

			if (!visited[nextx][nexty] && arr[nextx][nexty]) {
				visited[nextx][nexty] = true;
				q.push({ nextx, nexty });
			}
		}
	}

}