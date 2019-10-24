#include <bits/stdc++.h>
using namespace std;
uint32_t strToIP(string &ipstr)
{
    string::size_type pos1 = 0, pos2;
    uint32_t IP = 0;
    int i = 0;
    while (i < 4)
    {
        pos2 = ipstr.find('.', pos1);
        string ss = ipstr.substr(pos1, pos2 - pos1);
        IP <<= 8;
        IP += atoi(ss.c_str());
        ++i;
        pos1 = pos2 + 1;
    }
    return IP;
}
void print(uint32_t IP)
{
    uint8_t part[4];
    int i = 0;
    while (i < 4)
    {
        part[i] = IP & 0xFF;
        ++i;
        IP >>= 8;
    }
    cout << +part[3] << "."
         << +part[2] << "."
         << +part[1] << "."
         << +part[0] << endl;
}

int main(void)
{
    uint32_t IP, minIP, maxIP;
    string ipstr;
    int m;
    while (cin >> m)
    {
        minIP = ~0, maxIP = 0;
        int i;
        for (i = 0; i < m; ++i)
        {
            cin >> ipstr;
            IP = strToIP(ipstr);
            maxIP = max(IP, maxIP);
            minIP = min(IP, minIP);
        }
        if (m == 1)
        {
            print(minIP);
            print(~0);
        }
        else
        {
            bitset<32> maxipbit(maxIP), minipbit(minIP);
            for (i = 31; i >= 0; --i)
            {
                if (maxipbit[i] != minipbit[i])
                    break;
            }
            for (int j = i; j >= 0; --j)
                minipbit[j] = 0;
            minIP = minipbit.to_ulong();
            print(minIP);
            if (i == 31)
                print(0);
            else
                print(0xFFFFFFFF << (i + 1));
        }
    }
    return 0;
}
/*
3
192.85.160.177
192.85.160.178
192.85.160.183
*/