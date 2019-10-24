#include <iostream>
#include <string.h>
#include <ctype.h>

const float C = 12.01;
const float H = 1.008;
const float O = 16.00;
const float N = 14.01;

int main(void)
{
    char mol[80];
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {
        std::cin >> mol;

        int length = strlen(mol);
        char *p = mol + length - 1;
        float mass = 0.00;
        int num;

        while (p - mol != -1)
        {
            if (isalpha(*p))
            {
                num = 0; //注意清零
                sscanf(p + 1, "%d", &num);
                num = ((num == 0) ? 1 : num);
                switch (*p)
                {
                case 'C':
                    mass += num * C;
                    break;
                case 'H':
                    mass += num * H;
                    break;
                case 'O':
                    mass += num * O;
                    break;
                case 'N':
                    mass += num * N;
                    break;
                default:
                    break;
                }
                *p = '\0'; //去除使用过的字母，孤立数字，从而使用sscanf读取
            }
            --p;
        }
        std::cout.setf(std::ios::fixed);
        std::cout.precision(3);
        std::cout << mass << std::endl;
    }
    return 0;
}