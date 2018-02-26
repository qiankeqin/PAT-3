/*
1004. 成绩排名 (20)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 8000 B

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：
每个测试输入包含1个测试用例，格式为
  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试
用例中没有两个学生的成绩是相同的。

输出格式：
对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，
字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：
Mike CS991301
Joe Math990112
*/
#include <stdio.h>

struct Student{
	char name[11];
	char num[11];
	int score;
};

int main()
{
	int n,i;
	Student stu[1000],highest,lowest;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%s %s %d",stu[i].name,stu[i].num,&(stu[i].score));
	}
	highest = stu[0];
	lowest = stu[0];
	for(i=0;i<n;i++){
		if (stu[i].score > highest.score){
			highest = stu[i];
		}else if(stu[i].score < lowest.score){
			lowest = stu[i];
		}
	}
	printf("%s %s\n",highest.name,highest.num);
	printf("%s %s\n",lowest.name,lowest.num);
	return 0;
}