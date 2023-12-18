#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct coord
{
	int x;
	int y;
	int z;
};

int L, R, C;
char building[30][30][30];
coord s, e;
coord d[6] = { {0,0,1},{0,1,0},{0,0,-1}, {0,-1,0},{1,0,0},{-1,0,0} };
bool visited[30][30][30];

bool BFS();

int main()
{
	while (true) {
		scanf("%d %d %d", &L, &R, &C);

		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					char c; cin >> c;
					building[i][j][k] = c;

					if (c == 'S') {
						s.x = i;
						s.y = j;
						s.z = k;
					}
					if (c == 'E') {
						e.x = i;
						e.y = j;
						e.z = k;
					}
				}
			}
			cin.get();
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				memset(visited[i][j], false, sizeof(visited[i][j]));
				//for (int k = 0; k < R; k++) t[i][j][k] = 987654321;
			}
		}

		bool answer = BFS();

		if (answer) cout << "Escaped in (x)minute(s).\n";
		else cout << "Trapped!\n";
	}

	return 0;
}

bool BFS()
{
	queue<coord> q;
	q.push(s);

	visited[s.x][s.y][s.z] = true;

	while (!q.empty()) {
		int nowl = q.front().x;
		int nowr = q.front().y;
		int nowc = q.front().z;

		if (building[nowl][nowr][nowc] == 'E') return true;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nextl = nowl + d[i].x;
			int nextr = nowr + d[i].y;
			int nextc = nowc + d[i].z;

			if (nextl < 0 || L <= nextl || nextr < 0 || R <= nextr || nextc < 0 || C <= nextc) continue;

			if ((building[nextl][nextr][nextc] == '.' || building[nextl][nextr][nextc] == 'E') && !visited[nextl][nextr][nextc]) {
				visited[nextl][nextr][nextc] = true;
				q.push({ nextl, nextr, nextc });
			}
		}
	}

	return false;
}