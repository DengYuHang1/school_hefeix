#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> get_nextj(string pattern) 
{
    int strlen = pattern.length();
    vector<int> nextj(strlen, 0);
    int len = 0;
    int i = 1;

    while (i < strlen) 
    {
        if (pattern[i] == pattern[len]) 
        {
            len++;
            nextj[i] = len;
            i++;
        } 
        else 
        {
            if (len != 0) 
            {
                len = nextj[len - 1];
            } 
            else 
            {
                nextj[i] = 0;
                i++;
            }
        }
    }
    return nextj;
}

int KMP(string text, string pattern) 
{
    int len1 = text.length();
    int len2 = pattern.length();
    vector<int> nextj = get_nextj(pattern);

    int i = 0, j = 0;
    while (i < len1) 
    {
        if (pattern[j] == text[i]) 
        {
            i++;
            j++;
        }

        if (j == len2)         // 匹配成功
        {
            return i - j + 1;
        } 
        else if (i < len1 && pattern[j] != text[i]) 
        {
            if (j != 0)
                j = nextj[j - 1];
            else
                i++;
        }
    }
    return 0;
}

int main() 
{
    string text;
    string pattern;
    
    cout << "tsxt: " ;
    cin >> text;
    cout << "pattern: " ;
    cin >> pattern;

    cout << KMP(text, pattern);
    
    return 0;
}