#include <stdio.h>
#include <string.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

#define Num 6

typedef struct pallet
{
    int len;
    int wid;
    int count;
} Pallet;

int find(Pallet *arr, Pallet target, int num)
{
    int i;
    for (i = 0; i <= num; ++i)
        if (target.len == arr[i].len && target.wid == arr[i].wid)
            return i;
    return -1;
}

int main(void)
{
    Pallet Rec[Num], temp;
    temp.count = 0;
    int num = 0, ltemp, wtemp, j, ret, flag;
    while (scanf("%d %d", &ltemp, &wtemp) == 2)
    {
        num = 0;
        flag = 0;
        memset(Rec, 0, sizeof(Rec));

        Rec[num].len = max(ltemp, wtemp);
        Rec[num].wid = min(ltemp, wtemp);
        ++Rec[num].count;
        for (j = 0; j < 5; ++j)
        {
            scanf("%d %d", &ltemp, &wtemp);
            temp.len = max(ltemp, wtemp);
            temp.wid = min(ltemp, wtemp);

            if ((ret = find(Rec, temp, num)) == -1)
            {
                Rec[++num] = temp;
                ++Rec[num].count;
            }
            else
                ++Rec[ret].count;
        }

        if (num == 0 && Rec[num].count == 6)
            flag = 1;
        else if (num == 2 && Rec[0].count == 2 && Rec[1].count == 2 && Rec[2].count == 2)
        {
            if (Rec[0].len == Rec[1].len && (Rec[0].wid == Rec[2].len && Rec[1].wid == Rec[2].wid || Rec[0].wid == Rec[2].wid && Rec[1].wid == Rec[2].len))
                flag = 1;
            else if (Rec[0].len == Rec[1].wid && (Rec[0].wid == Rec[2].len && Rec[1].len == Rec[2].wid || Rec[0].wid == Rec[2].wid && Rec[1].len == Rec[2].len))
                flag = 1;
            else if (Rec[0].len == Rec[2].wid && (Rec[0].wid == Rec[1].len && Rec[2].len == Rec[1].wid || Rec[0].wid == Rec[1].wid && Rec[1].len == Rec[2].len))
                flag = 1;
            else if (Rec[0].len == Rec[2].len && (Rec[0].wid == Rec[1].len && Rec[2].wid == Rec[1].wid || Rec[0].wid == Rec[1].wid && Rec[1].len == Rec[2].wid))
                flag = 1;
        }
        else if (num == 1)
        {
            if (Rec[0].count == 4 && Rec[1].count == 2 && Rec[1].len == Rec[1].wid && (Rec[1].len == Rec[0].len || Rec[1].len == Rec[0].wid))
                flag = 1;
            else if (Rec[0].count == 2 && Rec[1].count == 4 && Rec[0].len == Rec[0].wid && (Rec[0].len == Rec[1].len || Rec[0].len == Rec[1].wid))
                flag = 1;
        }
        else
            flag = 0;

        if (flag == 1)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}