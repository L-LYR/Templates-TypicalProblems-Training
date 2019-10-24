#include <iostream>

int main(void)
{
    char str[80];
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {
        std::cin >> str;
        int score = 0, sum = 0;
        for (char *p = str; *p != '\0'; ++p)
        {
            if (*p == 'O')
                ++score;
            else
                score = 0;
            sum += score;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
