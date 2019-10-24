#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    int length;
    int i, times = 1;
    int seq_num[10] = {0};
    while (scanf("%d", &length) && length != 0)
    {
        int *seq = (int *)malloc(sizeof(int) * length);
        for (i = 0; i < length; i++)
        {
            scanf("%d", seq + i);
            seq_num[*(seq + i)]++;
        }
        int *ans = (int *)malloc(sizeof(int) * length);
        printf("Game %d:\n", times++);
        while (1)
        {
            int flag = 0;
            int A = 0;
            int ans_num[10] = {0};
            for (i = 0; i < length; i++)
            {
                scanf("%d", ans + i);
                ans_num[*(ans + i)]++;
                if (*(ans + i) == *(seq + i))
                    A++;
                if (*(ans + i) == 0)
                    flag++;
            }
            if (flag == length)
                break;
            int B = 0;
            for (i = 0; i < 10; i++)
                B += (ans_num[i] < seq_num[i] ? ans_num[i] : seq_num[i]);
            B -= A;
            printf("    (%d,%d)\n", A, B);
        }
        memset(seq_num, 0, sizeof(int) * 10);
    }
    // fclose(b);
    return 0;
}