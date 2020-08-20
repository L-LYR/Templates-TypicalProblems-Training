#include <iostream>

using std::cout;
using std::endl;
namespace bit_opt
{
    int32_t add(int32_t lhs, int32_t rhs)
    {
        if (lhs == 0)
            return rhs;
        if (rhs == 0)
            return lhs;
        int32_t sum = rhs ^ lhs;
        int32_t carry = (rhs & lhs) << 1;
        while (carry)
        {
            int32_t tmp = sum;
            sum = sum ^ carry;
            carry = (tmp & carry) << 1;
        }
        return sum;
    }

    int32_t sub(int32_t lhs, int32_t rhs)
    {
        return add(lhs, add(~rhs, 1));
    }

    int32_t abs(int32_t x)
    {
        int32_t nx = add(~x, 1);
        int32_t sx = x >> 31;
        return (sx & nx) | (~sx & x);
    }

    int32_t mul(int32_t lhs, int32_t rhs)
    {
        int32_t abs_lhs = abs(lhs);
        int32_t abs_rhs = abs(rhs);
        int32_t proc = 0;

        while (abs_rhs)
        {
            if ((abs_rhs & 1))
                proc = add(proc, abs_lhs);
            abs_lhs <<= 1;
            abs_rhs >>= 1;
        }

        int32_t s = (lhs >> 31) ^ (rhs >> 31);

        return (s & add(~proc, 1)) | (~s & proc);
    }

    int32_t div(int32_t lhs, int32_t rhs)
    {
        int32_t abs_lhs = abs(lhs);
        int32_t abs_rhs = abs(rhs);

        int32_t quot = 0;
        for (int32_t i = 31; i >= 0; i--)
        {
            if (abs_lhs >> i >= abs_rhs)
            {
                quot = add(quot, 1 << i);
                abs_lhs = sub(abs_lhs, abs_rhs << i);
            }
        }
        int32_t rs = (rhs >> 31);
        int32_t s = (lhs >> 31) ^ rs;
        int32_t rem = (rs & add(~abs_rhs, 1)) | (~rs | abs_rhs);

        return (s & add(~quot, 1)) | (~s & quot);
    }
} // namespace bit_opt

int main(void)
{
    cout << bit_opt::add(-1, 1) << endl;
    cout << bit_opt::sub(40, 60) << endl;
    cout << bit_opt::mul(50, 40) << endl;
    cout << bit_opt::div(50, 10) << endl;
    return 0;
}