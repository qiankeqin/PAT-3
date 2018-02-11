/*
1009. 说反话 (20)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 8000 B

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串
由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单
词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come

输出样例：
Come I Here World Hello
*/

#include <stdio.h>

int main()
{
	int i = 0;
	char a[80][100];
	while(1)
	{
		scanf("%s",*(a + i));
		i++;
		if(getchar() == '\n')
		{
			break;	
		}
	}
	while(--i)
	{
		printf("%s ",*(a+i));
	}
	printf("%s",*a);
	return 0;	
}