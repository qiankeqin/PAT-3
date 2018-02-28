"""
1013. 数素数 (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B

令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
"""

# Python is too slow
m,n = str(input()).split()
m,n = int(m),int(n)
isPrime = [ True for x in range(0,10000)]  #15000
isPrime[0],isPrime[1] = False,False
for x,xIsPrime in enumerate(isPrime):
    if xIsPrime:
        for y in range(2*x,10000,x):    #15000
            isPrime[y] = False
prime = [ x for x,xIsPrime in enumerate(isPrime) if xIsPrime]
cnt = 0
for i in range(m-1,n):
    print(prime[i],end = ' 'if cnt % 10 != 9 and i != n-1 else '\n')
    cnt += 1