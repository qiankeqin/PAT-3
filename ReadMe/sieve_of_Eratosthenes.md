# 埃拉托斯特尼筛法
> 埃拉托斯特尼筛法，简称埃氏筛或爱氏筛，是一种由希腊数学家埃拉托斯特尼所提出的一种简单检定素数的算法。要得到自然数n以内的全部素数，必须把不大于根号n的所有素数的倍数剔除，剩下的就是素数。

**时间复杂度**
O(nloglogn)

## 步骤
1. 首先将2到n范围内的整数写下来;
2. 其中2是最小的素数,将表中所有的2的倍数划去;
3. 表中剩下的最小的数字就是3，他不能被更小的数整除，所以3是素数。再将表中所有的3的倍数划去;
   ……
4. 以此类推，如果表中剩余的最小的数是m，那么m就是素数。然后将表中所有m的倍数划去;
5. 像这样反复操作，就能依次枚举n以内的素数

## Python实现
```python
isPrime = { x:True for x in range(2,n+1)}
for key,value in isPrime.items():
    if value:
        for i in range(2*key,n+1,key):
            isPrime[i] = False
prime = [key for key,value in isPrime.items() if value]
```
