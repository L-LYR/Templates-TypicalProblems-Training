#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        stack<char> s;
        char c;
        int n;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; ++i)
        {
            scanf("%c", &c);
            if (c == ')' && (!s.empty() && s.top() == '('))
                s.pop();
            else
                s.push(c);
        }
        printf("%d\n", s.size());
    }

    return 0;
}