/*
1004. Counting Leaves (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who 
have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number 
of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, 
followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the 
root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority 
level starting from the root. The numbers must be printed in a line, separated by a space, and there 
must be no extra space at the end of each line.The sample case represents a tree with only 2 nodes, 
where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on 
the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02

Sample Output
0 1
*/

#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 101;
int count[MAXN] = {0};

struct node{
    int layer;
    queue<int> child;
}r[MAXN],no;

int main(){
    int n,m,id,k,idn,deep,t;
    queue<node> q;
    //freopen("in/in.txt","r",stdin);
    cin >> n >> m;
    while(m--){
        scanf("%d %d",&id,&k);
        for(int i = 0; i < k; i++){
            scanf("%d",&t);
            r[id].child.push(t);
        }
    }
    r[1].layer = 1;
    q.push(r[1]);
    while(!q.empty()){
        no = q.front();
        deep = no.layer;
        q.pop();
        if(no.child.empty()) count[deep]++;
        while(!no.child.empty()){
            idn = no.child.front();
            no.child.pop();
            r[idn].layer = deep + 1;
            q.push(r[idn]);
        }
    }
    for(int i = 1; i < deep; i++){
        printf("%d ",count[i]);
    }
    printf("%d\n",count[deep]);
    return 0;
}