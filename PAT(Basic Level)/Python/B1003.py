"""
1003. 我要通过！(20)

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，
系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 
每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占
一行，字符串长度不超过100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
"""

n = int(input())
for k in range(n):
    # p1:P的个数; t1:T的个数; a1:A的个数; p2:P所在的位置; t2:T所在的位置
    p1,t1,a1,p2,t2 = 0,0,0,0,0 
    s = str(input())
    for i,c in enumerate(s):
        if c == 'P':
            p1, p2= p1+1, i
        elif c == 'T':
            t1, t2 = t1+1, i
        elif c == 'A':
            a1 += 1
    # P不只出现1次(0次) or T不只出现1次(0次) or 有其他字符 or (P出现在T之前,PT相邻的情况)
    if p1 != 1 or t1 != 1 or p1 + t1 + a1 < len(s) or t2 <= p2 + 1:
        print("NO")
    else:
        # P所在的位置index即P之前A的个数
        if p2 * (t2 - p2 - 1) == len(s) - t2 - 1:	
            print("YES")
        else:
            print("NO")