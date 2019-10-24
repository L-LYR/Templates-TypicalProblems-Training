#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int num;
    Node *prev;
    Node *next;
};

Node *CreateCircle(int N)
{
    int i;
    Node *start = (Node *)malloc(sizeof(Node) * N);
    for (i = 0; i < N; ++i)
    {
        (start + i)->num = i + 1;
        (start + i)->prev = (start + i - 1);
        (start + i)->next = (start + i + 1);
    }
    start->prev = start + N - 1;
    (start + N - 1)->next = start;
    return start;
}

void remove(Node *del)
{
    del->prev->next = del->next;
    del->next->prev = del->prev;
    printf("%3d", del->num);
    del->num = 0;
}

int main(void)
{
    // FILE *a = freopen("input.txt", "r", stdin);
    // FILE *b = freopen("output.txt", "w", stdout);
    int N, k, m;
    Node *start, *pA, *pB;
    int i, count;
    while (scanf("%d %d %d", &N, &k, &m) == 3 && N != 0)
    {
        count = 0;
        start = CreateCircle(N);
        pA = start->prev;
        pB = start;
        while (N > 0)
        {
            for (i = 1; i <= k; ++i)
            {
                while (pA->next->num == 0)
                    pA = pA->next;
                pA = pA->next;
            }

            for (i = 1; i <= m; ++i)
            {
                while (pB->prev->num == 0)
                    pB = pB->prev;
                pB = pB->prev;
            }

            if (count)
                printf(",");
            if (pA != pB)
            {
                remove(pA);
                --N;
            }
            remove(pB);
            --N;

            ++count;
        }
        free(start);
        printf("\n");
    }
    // fclose(a);
    // fclose(b);
    return 0;
}