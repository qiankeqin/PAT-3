/*
1003. Emergency (25)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 16000 B
As an emergency rescue team leader of a city, you are given a special map of your country. The 
map shows several scattered cities connected by some roads. Amount of rescue teams in each city 
and the length of each road between any pair of cities are marked on the map. When there is an 
emergency call to you from some other city, your job is to lead your men to the place as quickly 
as possible, and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case. For each test case, the first line contains 4 positive 
integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), 
M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, 
respectively. The next line contains N integers, where the i-th integer is the number of rescue 
teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, 
which are the pair of cities connected by a road and the length of that road, respectively. It is 
guaranteed that there exists at least one path from C1 to C2.

Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 
and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed 
at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4
*/


// Dijkstra算法
//判断条件 首先是否最短,其次该条路径上能交叫的帮手最多
//ci[i] 为当前城市的帮手数
//pc[i] 为从源点到当前点i的路径数
//rt[i] 为从源点到当前点i的最大帮手数
//dp[i] 为从源点到当前点的最短距离

//状态转移方程( j 为访问过的点，i 为未访问的点)：
// 1.由 j 到 i 的路径的距离比原先小：
//  dp[i] = dp[j] + dp[j][i];
//  rt[i] = rt[j] + ci[j];
//  pc[i] = pc[j]
// 2.由 j 到 i 的路径的距离与原先相等：
//  dp[i] 不变;
//  rt[i] = max(rt[i],rt[j] + ci[i]);
//  pc[i] += pc[j]
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 520,INF = 12345678;
int n,ci[MAXN],v[MAXN][MAXN],vis[MAXN],dp[MAXN],pc[MAXN],rt[MAXN];

void find(int start,int end){
    fill(dp,dp+MAXN,INF);
    dp[start] = 0;              //初始条件
    pc[start] = 1;
    rt[start] = ci[start];
    for(int cnt = 0; cnt < n; cnt++){
        int minp = INF,j = -1;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && dp[i] < minp){
                j = i;
                minp = dp[i];
            }
        }
        if(j != -1) vis[j] = 1;
        if(j == end) break;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(dp[j]+v[j][i] < dp[i]){
                    dp[i] = dp[j]+v[j][i];
                    pc[i] = pc[j];
                    rt[i] = rt[j]+ci[i];
                }else if(dp[j]+v[j][i] == dp[i]){
                    pc[i] +=pc[j];
                    rt[i] = max(rt[i],rt[j]+ci[i]);
                }
            }
        }
    }
    printf("%d %d\n",pc[end],rt[end]);
}

int main(){
    int m,c1,c2,a,b,c;
    //freopen("in/in.txt","r",stdin);
    fill(v[0],v[0]+MAXN*MAXN,INF);
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i++){
        cin >> ci[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a][b] = v[b][a] = c;
    }
    find(c1,c2);
    return 0;
}