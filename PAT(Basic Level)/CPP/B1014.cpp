/*
1014. 福尔摩斯的约会 (20)
时间限制 100 ms
内存限制 65536 kB
代码长度限制 8000 B

大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英
文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14
个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个
位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED
表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出样例：
THU 14:04
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char weekday[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(int argc, char const *argv[]){
	char str1[100],str2[100],str3[100],str4[100];
	char c1,c2;
	char *p,*q;
	int t = 0;
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	p = str1;
	q = str2;
	while(*p != '\0' && *q != '\0'){
		if(*p >= 'A' && *p <= 'G' && *q == *p ){
			c1 = *p;
			break;
		}
		p++;
		q++;
	}
	p++;q++;
	while(*p != '\0' && *q != '\0'){
		if(((*p >= 'A'&& *q <='N')||(*p >='0' && *p <= '9'))&& *p == *q){
			c2 = *p;
			break;
		}
		p++;
		q++;
	}
	p=str3;
	q=str4;
	while(*p != '\0' && *q != '\0'){
		if(((*p >= 'a' && *p <= 'z')||(*p >= 'A' && *p <= 'Z'))&& *p == *q){
			break;
		}
		t++;
		p++;
		q++;
	}
	printf("%s ", weekday[c1-'A']);
	printf("%02d:",(c2 >= 'A' && c2 <= 'N')?c2-'A'+10:c2-'0');
	printf("%02d\n", t);
	return 0;
}