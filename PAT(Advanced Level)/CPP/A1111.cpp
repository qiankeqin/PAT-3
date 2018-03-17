/*
1111. Online Map (30)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your 
user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the 
total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in 
the format:
V1 V2 one-way length time
where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, 
or 0 if not; length is the length of the street; and time is the time taken to pass the street.
Finally a pair of source and destination is given.

Output Specification:
For each case, first print the shortest path from the source to the destination with distance D in the format:
Distance = D: source -> v1 -> ... -> destination
Then in the next line print the fastest path with total time T:
Time = T: source -> w1 -> ... -> destination
In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the 
fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.
In case the shortest and the fastest paths are identical, print them in one line in the format:
Distance = D; Time = T: source -> u1 -> ... -> destination

Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5

Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 501, INF = 123456789;
int vl[MAXN][MAXN], vt[MAXN][MAXN], dpl[MAXN], dpt[MAXN], lg[MAXN], vis[MAXN], pre[MAXN], path1[MAXN], path2[MAXN];

void dealPath(int t, int pre[], int path[], int &cnt) {
	for (int i = t; i != -1; i = pre[i]) {
		path[cnt++] = i;
	}
	reverse(path, path + cnt);
}

void DJT_findShortest(int s, int e, int n, int p[], int &j) {
	fill(vis, vis + MAXN, 0);
	fill(dpl, dpl + MAXN, INF);
	fill(dpt, dpt + MAXN, INF);
	fill(pre, pre + MAXN, -1);
	dpl[s] = 0;
	dpt[s] = 0;
	for (int cnt = 0; cnt < n; cnt++) {
		int minl = INF, j = -1;
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0 && dpl[i] < minl) {
				minl = dpl[i];
				j = i;
			}
		}
		if (j != -1) vis[j] = 1;
		if (j == e) break;
		for (int i = 0; i < n; i++) {
			if (dpl[j] + vl[j][i] < dpl[i]) {
				dpl[i] = dpl[j] + vl[j][i];
				dpt[i] = dpt[j] + vt[j][i];
				pre[i] = j;
			}else if (dpl[j] + vl[j][i] == dpl[i] && dpt[j] + vt[j][i] < dpt[i]) {
				dpt[i] = dpt[j] + vt[j][i];
				pre[i] = j;
			}
		}
	}
	dealPath(e, pre, p, j);
}

void DJT_findFastest(int s, int e, int n, int p[], int &j) {
	fill(vis, vis + MAXN, 0);
	fill(dpt, dpt + MAXN, INF);
	fill(lg, lg + MAXN, INF);
	fill(pre, pre + MAXN, -1);
	dpt[s] = 0;
	lg[s] = 1;
	for (int cnt = 0; cnt < n; cnt++) {
		int mint = INF, j = -1;
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0 && dpt[i] < mint) {
				mint = dpt[i];
				j = i;
			}
		}
		if (j != -1) vis[j] = 1;
		if (j == e) break;
		for (int i = 0; i < n; i++) {
			if (dpt[j] + vt[j][i] < dpt[i]) {
				dpt[i] = dpt[j] + vt[j][i];
				lg[i] = lg[j] + 1;
				pre[i] = j;
			}else if (dpt[j] + vt[j][i] == dpt[i] && lg[i] > lg[j] + 1) {
				lg[i] = lg[j] + 1;
				pre[i] = j;
			}
		}
	}
	dealPath(e, pre, p, j);
}

bool isSame(int p1[], int p2[], int j1, int j2) {
	bool diff = true;
	if (j1 == j2) {
		int i;
		for (i = 0; i < j1; i++)
			if (p1[i] != p2[i]) break;
		if (i == j1) diff = false;
	}
	return diff;
}

int main(){
	int n, m, a, b, ow, le, ti, s, t, j1 = 0, j2 = 0;
	fill(vl[0], vl[0] + MAXN * MAXN, INF);
	fill(vt[0], vt[0] + MAXN * MAXN, INF);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &a, &b, &ow, &le, &ti);
		if (ow == 1) {
			vl[a][b] = le;
			vt[a][b] = ti;
		}else {
			vl[a][b] = vl[b][a] = le;
			vt[a][b] = vt[b][a] = ti;
		}
	}
	scanf("%d %d", &s, &t);
	DJT_findShortest(s, t, n, path1, j1);
	DJT_findFastest(s, t, n, path2, j2);

	printf("Distance = %d", dpl[t]);
	if (isSame(path1,path2,j1,j2)){
		printf(":");
		for (int i = 0; i < j1; i++) {
			printf(" %d%s", path1[i], (i==j1-1)?"\n":" ->");
		}
	}else {
		printf("; ");
	}
	printf("Time = %d:", dpt[t]);
	for (int i = 0; i < j2; i++) {
		printf(" %d%s", path2[i], (i == j2 - 1) ? "\n" : " ->");
	}
	return 0;
}