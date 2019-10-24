#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct command
{
    char name[3];
    int A;
    int *x;
} Command;
Command *cmd;
int r, c, n, q;

void calculate(int qr, int qc)
{
    int i, flag, j;
    int x, dr, dc;
    char *p;
    for (i = 0; i < n; ++i)
    {
        flag = 1;
        if (cmd[i].name[0] == 'E')
        {
            if (cmd[i].x[0] == qr && cmd[i].x[1] == qc)
            {
                qr = cmd[i].x[2];
                qc = cmd[i].x[3];
            }
            else if (cmd[i].x[2] == qr && cmd[i].x[3] == qc)
            {
                qr = cmd[i].x[0];
                qc = cmd[i].x[1];
            }
        }
        else
        {
            dr = dc = 0;
            p = cmd[i].name;
            for (j = 0; j < cmd[i].A; ++j)
            {
                x = cmd[i].x[j];
                if (p[0] == 'I')
                {
                    if (p[1] == 'R' && x <= qr)
                        ++dr;
                    else if (p[1] == 'C' && x <= qc)
                        ++dc;
                }
                else
                {
                    if (p[1] == 'R' && x < qr)
                        --dr;
                    else if (p[1] == 'C' && x < qc)
                        --dc;
                    else if ((p[1] == 'R' && x == qr) || (p[1] == 'C' && x == qc))
                    {
                        flag = 0;
                        break;
                    }
                }
            } //for j
            qr += dr;
            qc += dc;
        } //else
        if (flag == 0)
            break;
    } //for i
    if (flag == 1)
        printf("moved to (%d,%d)\n", qr, qc);
    else
        printf("GONE\n");
}

int main(void)
{
    // FILE *a = freopen("input.txt", "r", stdin);
    // FILE *b = freopen("output.txt", "w", stdout);
    int i, *ip, lim, j, k = 0, qr, qc;
    while (scanf("%d %d %d", &r, &c, &n) == 3 && r != 0)
    {
        cmd = (Command *)malloc(sizeof(Command) * n);
        memset(cmd, 0, sizeof(Command) * n);

        for (i = 0; i < n; ++i)
        {
            scanf("%3s", cmd[i].name);
            if (*(cmd[i].name) == 'E')
            {
                ip = cmd[i].x = (int *)malloc(sizeof(int) * 4);
                scanf("%d %d %d %d", ip, ip + 1, ip + 2, ip + 3);
            }
            else
            {
                scanf("%d", &(cmd[i].A));
                lim = cmd[i].A;
                ip = cmd[i].x = (int *)malloc(sizeof(int) * lim);
                for (j = 0; j < lim; ++j)
                    scanf("%d", ip + j);
            }
        } //for i

        if (k != 0)
            printf("\n");
        printf("Spreadsheet #%d\n", ++k);

        scanf("%d", &q);
        for (i = 0; i < q; ++i)
        {
            scanf("%d %d", &qr, &qc);
            printf("Cell data in (%d,%d) ", qr, qc);
            calculate(qr, qc);
        }

        for (i = 0; i < n; ++i)
            free(cmd[i].x);
        free(cmd);
    }
    // fclose(a);
    // fclose(b);
    return 0;
}