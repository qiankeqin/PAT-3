"""
1007. 素数对猜想 (20)

让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在
无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式：
每个测试输入包含1个测试用例，给出正整数N。

输出格式：
每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20

输出样例：
4

"""

n = int(input())
isPrime = { x:True for x in range(2, n + 1)}
for key,value in isPrime.items():           # 埃拉托斯特尼筛法
    if value:
        for i in range(2 * key, n + 1, key):
            isPrime[i] = False
prime = [key for key,value in isPrime.items() if value]
newl = [ i for i in range(len(prime)-1) if prime[i+1] - prime[i] == 2 ]
print(len(newl))