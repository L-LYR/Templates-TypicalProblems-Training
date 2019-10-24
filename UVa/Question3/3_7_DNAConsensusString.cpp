#include <stdio.h>
#include <string.h>

#define max(x, y) ((x) >= (y) ? (x) : (y))
#define MaxInFour(a, b, c, d) max(max(a, b), max(c, d))

typedef enum nucleotide
{
    A,
    C,
    G,
    T,
    N
} Nucleotide;

int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    int Times, m, n, ConsensusError, Max;
    int t, i, j, k;
    int count[4][1000];
    char ConsensusString[1010];
    Nucleotide X;

    scanf("%d", &Times);
    getchar(); //skip \n
    for (t = 0; t < Times; ++t)
    {
        memset(count, 0, sizeof(count));

        scanf("%d %d", &m, &n);
        getchar(); //skip \n
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                switch (getchar())
                {
                case 'A':
                    ++count[A][j];
                    break;
                case 'C':
                    ++count[C][j];
                    break;
                case 'G':
                    ++count[G][j];
                    break;
                case 'T':
                    ++count[T][j];
                    break;
                }
            }          //for n
            getchar(); //skip \n
        }              //for m

        ConsensusError = 0;
        memset(ConsensusString, 0, sizeof(ConsensusString));
        for (j = 0; j < n; ++j)
        {
            X = N;
            Max = MaxInFour(count[A][j], count[C][j], count[G][j], count[T][j]);
            for (k = 0; k <= T; ++k)
            {
                if (count[k][j] == Max && X == N)
                {
                    X = (Nucleotide)k;
                    switch (X)
                    {
                    case A:
                        ConsensusString[j] = 'A';
                        break;
                    case C:
                        ConsensusString[j] = 'C';
                        break;
                    case G:
                        ConsensusString[j] = 'G';
                        break;
                    case T:
                        ConsensusString[j] = 'T';
                        break;
                    }
                }
                if (k != X)
                    ConsensusError += count[k][j];
            }
        }
        ConsensusString[j] = '\0';
        printf("%s\n%d\n", ConsensusString, ConsensusError);

    } //for times
    // fclose(b);
    return 0;
}