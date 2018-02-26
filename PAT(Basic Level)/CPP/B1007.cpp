/*
1007. 素数对猜想 (20)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 8000 B

让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶
数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。现给定任意正整数N (< 105)，请计算不
超过N的满足猜想的素数对的个数。

输入格式：
每个测试输入包含1个测试用例，给出正整数N。

输出格式：
每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20

输出样例：
4
*/
#include <stdio.h>
#include <math.h>

int isSushu(int a)
{
	int i,m;
	m = sqrt(a);
	for(i = 2; i<=m; i++)
	{
		if(a%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n,i,pn,pn1,j = 0;
	scanf("%d",&n);
	pn = 2;
	for(i = 2; i <= n; i++)
	{
		if(isSushu(i))
		{
			pn1 = pn;
			pn = i;
			if(pn - pn1 == 2)
			{
				j++;
			}
		}
	}
	printf("%d",j);
	return 0;
	
}
