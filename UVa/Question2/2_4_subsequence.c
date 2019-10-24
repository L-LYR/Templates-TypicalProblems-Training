#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int n, m, j = 1;
	while (scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0)
	{
		int i;
		double sum = 0;
		for (i = n; i <= m; i++)
			sum += (1.0 / i)*(1.0 / i);//注意溢出
		printf("Case %d: %.5lf\n", j++, sum);
	}
	system("pause");
	return 0;
}