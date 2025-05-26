#include <bits/stdc++.h>
using namespace std;

// User function template for C++




// User function template for C++

// User function template for C++

class Solution {
  public:
    string convertToWords(int n)
    {
        string s[100];
        s[0] = "Zero";
        s[1] = "One";
        s[2] = "Two";
        s[3] = "Three";
        s[4] = "Four";
        s[5] = "Five";
        s[6] = "Six";
        s[7] = "Seven";
        s[8] = "Eight";
        s[9] = "Nine";
        s[10] = "Ten";
        s[11] = "Eleven";
        s[12] = "Twelve";
        s[13] = "Thirteen";
        s[14] = "Fourteen";
        s[15] = "Fifteen";
        for (int i = 16; i <= 19; i++)
        {
            s[i] = s[i % 10] + "teen";
        }
        s[18]="Eighteen";
        s[20] = "Twenty";
        if (n <= 20)
        {
            return s[n];
        }
        s[30] = "Thirty";
        s[40] = "Forty";
        s[50] = "Fifty";
        s[60] = "Sixty";
        s[70] = "Seventy";
        s[80] = "Eighty";
        s[90] = "Ninety";

        vector<pair<int, int>> v;
        string tmp = to_string(n);
        int left;
        int right;

        if (tmp.size() % 3 == 0)
        {
            left = 0;
            right = 2;
        }
        else if (tmp.size() % 3 == 1)
        {
            left = 0;
            right = 0;
        }
        else
        {
            left = 0;
            right = 1;
        }

        while (left < tmp.size() && right < tmp.size())
        {
            v.push_back({left, right});
            left = right + 1;
            right = right + 3;
        }

        string s2[4];
        s2[0] = "Hundred";
        s2[1] = "Thousand";
        s2[2] = "Million";
        s2[3] = "Billion";

        string res = "";
        for (int i = 0; i < v.size(); i++)
        {
            int idx = v[i].first;
            int jdx = v[i].second;
            bool ok = false;
            while (idx <= jdx)
            {
                if (tmp[idx] != '0')
                {
                    if (jdx - idx == 2)
                    {
                        res = res + s[tmp[idx] - '0'] + " " + s2[0] + " ";
                        idx++;
                    }
                    else if (jdx - idx == 1)
                    {
                        if (tmp[idx] == '1')
                        {
                            int tmp2=(tmp[idx]-'0')*10+(tmp[jdx]-'0');
                            res=res+s[tmp2]+" ";
                            idx=jdx;
                        }
                        else
                        {
                            int tmp2 = (tmp[idx] - '0') * 10;
                            res = res + s[tmp2] + " ";
                        }
                        idx++;
                    }
                    else
                    {
                        res = res + s[tmp[idx] - '0'] + " ";
                        idx++;
                    }
                    ok = true;
                }
                else
                {
                    idx++;
                }
            }
            if (ok == true && i != v.size() - 1)
            {
                int tmp2 = v.size() - i - 1;
                res = res + s2[tmp2] + " ";
            }
        }
        res.pop_back();
        return res;
    }
};