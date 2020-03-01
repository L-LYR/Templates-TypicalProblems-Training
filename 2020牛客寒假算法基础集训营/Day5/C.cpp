// This question is ambiguous.
// "Used Functions" doesn't contain function declarations.
// We just need to output the definition of functions in 
// format like
// <return type> <function name>(<type of parameter I>...)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <set>
#include <stack>
using namespace std;
const int maxn = 105000;
char s[maxn], *p, *q, t[maxn], c, *r, *l;
int main(void)
{
    p = s;
    while ((c = getchar()) != EOF)
        *p++ = c;
    p = s;
    q = t;
    while (*p)
    {
        if (*p == '#')
            p = strchr(p, '\n');
        else if (*p == '/')
        {
            ++p;
            if (*p == '/')
                p = strchr(p, '\n');
            else if (*p == '*')
            {
                do
                {
                    p = strchr(p, '*');
                    ++p;
                } while (*p != '/');
            }
        }
        else if (*p == '{')
        {
            stack<char> cs;
            cs.push(*p);
            while (!cs.empty())
            {
                ++p;
                if (*p == '{')
                    cs.push(*p);
                else if (*p == '}' && !cs.empty())
                    cs.pop();
            }
        }
        else
            *q++ = *p;
        ++p;
    }
    q = t;
    p = s;
    memset(s, 0, sizeof(s));
    while (true)
    {
        r = strchr(q, '\n');
        if (r == NULL)
            break;
        while (q != r)
        {
            *p++ = *q++;
            if (*q == ' ')
                *p++ = ' ';
            while (*q == ' ')
                *q++;
        }
        q++;
    }
    q = s;
    set<string> ans;
    while (true)
    {
        p = strchr(q, '(');
        if (p == NULL)
            break;
        q = p - 1;
        if (*q == ' ')
            --q;
        string tmp = "";
        while (*q != ' ')
            tmp.push_back(*q--);
        tmp.push_back(*q--);
        while (*q != ';' && *q != ')' && q != s - 1)
            tmp.push_back(*q--);
        while (tmp.back() == ' ')
            tmp.pop_back();
        reverse(tmp.begin(), tmp.end());

        q = p + 1;
        tmp.push_back('(');
        while (true)
        {
            if (*q == ' ')
                ++q;
            while (*q != ',' && *q != ')')
                tmp.push_back(*q++);
            while (tmp.back() == ' ')
                tmp.pop_back();
            while (tmp.back() != ' ' && tmp.back() != '(')
                tmp.pop_back();
            if (tmp.back() == ' ')
                tmp.pop_back();
            tmp.push_back(*q);
            if (*q == ')')
                break;
            else
                q++;
        }
        q++;
        if (*q == ';')
            ++q;
        else
        {
            if (tmp.substr(0, 6) == "inline")
                tmp.erase(tmp.begin(), tmp.begin() + 7);
            ans.insert(tmp);
        }
    }
    for (auto i : ans)
        cout << i << endl;

    return 0;
}