class Solution {
public:
    int maxRepeating(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    int cnt = 0;
    if(blen > alen) return cnt;
    else
    {
        string b_copy = b;
        while(1)
        {
            int currPos = a.find(b);
            if(currPos != -1)
            {
                cnt++;
                currPos = -1;
                b += b_copy;
            }
            else break;
        }
        return cnt;
    }
    }
};
