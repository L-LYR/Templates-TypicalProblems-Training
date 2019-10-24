#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int a, b, c, i = 1;
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		int x, flag = 0;
		for (x = 10; x < 100; x++)
			if (x % 3 == a && x % 5 == b && x % 7 == c)//暴力即可
			{
				flag = 1;
				break;
			}
		if (flag)printf("Case %d: %d\n", i, x);
		else printf("Case %d: No answer\n", i);
		i++;
	}
	system("pause");
	return 0;
}