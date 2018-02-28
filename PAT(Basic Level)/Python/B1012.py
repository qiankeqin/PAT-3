"""
1012. 数字分类 (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间
以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例1：
30 11 2 9.7 9

输入样例2：
8 1 2 4 5 6 7 9 16

输出样例2：
N 11 2 N 9

"""

l = [int(x) for x in str(input()).split()]
n,num = l[0],l[1:]
res = [0,0,0,0,0]
cnt2,cnt4 = 0,0
for x in num:
    if x%5 == 0 and x % 2 == 0:
        res[0] += x
    elif x%5 == 1:
        x = x if cnt2 % 2 == 0 else -x
        res[1], cnt2 = res[1]+x, cnt2+1
    elif x%5 == 2:
        res[2] += 1
    elif x%5 == 3:
        res[3], cnt4 = res[3]+x, cnt4+1
    elif x%5 == 4:
        res[4] = x if res[4] < x else res[4]

res[0] = "N" if res[0] == 0 else res[0]
res[1] = "N" if cnt2 == 0 else res[1]
res[2] = "N" if res[2] == 0 else res[2]
res[3] = "N" if cnt4 == 0 else str(round(1.0*res[3]/cnt4,1))
res[4] = "N" if res[4] == 0 else res[4]
for x in res[:-1]:
    print(x,end=' ')
print(res[-1])