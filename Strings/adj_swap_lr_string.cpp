#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    // XL->LX
    // RX->XR
    int findPos(string s, int k, char ch)
    {
        for(int i = k + 1; i < s.size(); ++i)
        {
            if(s[i] != 'X')
            {
                if(s[i] == ch)
                    return i;
                else 
                    return -1;
            }
        }
        return -1;
    }
    void swap(string s, int i, int j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    bool isSwappable(int i, string e, string s)
    {
        if((s[i] == 'L' && e[i] == 'R') || (s[i] == 'R' && e[i] == 'L'))
            return false;
        if(s[i] == 'X' && e[i] == 'L')
        {
            // find pos of L in s
            int pos = findPos(s, i, 'L');
            if(pos == -1) return false;
            swap(s, i, pos);
            return true;
        }
        if(s[i] == 'R' && e[i] == 'X')
        {
            int pos = findPos(e, i, 'R');
            if(pos == -1) return false;
            // if in s, till pos all Xs then swap
            for(int j = i; j <= pos; ++pos)
            {
                if(s[j] != 'X')
                    return false;
            }
            
            swap(s, i, pos);
            return true;
        } 
        return false;      
    } 
    bool canTransform(string start, string end) 
    {
        if(end.size() != start.size())
            return false;
        int n = end.size();

        for(int i = 0; i < n; ++i)
        {
            if(end[i] != start[i])
            {
                if(isSwappable(i, end, start))
                {
                    ++i;
                }
                else
                {
                    return false;
                }
                
            }
        }
        return true;   
    }
};

int main()
{
    Solution obj;
    obj.
}