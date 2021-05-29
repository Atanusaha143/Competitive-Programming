class Solution {
public:
    string check(string currPrefix, string checkPrefix)
    {
        string ans;
        int len1 = currPrefix.size();
        int len2 = checkPrefix.size();
        if(len1 < len2)
        {
            for(int i=0; i<len1; i++)
            {
                if(currPrefix[i] == checkPrefix[i]) ans += currPrefix[i];
                else break;
            }
        }
        else
        {
            for(int i=0; i<len2; i++)
            {
                if(currPrefix[i] == checkPrefix[i]) ans += currPrefix[i];
                else break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& vec)
    {

        string currPrefix = vec[0];
        int len = vec.size();
        for(int i=1; i<len; i++)
            currPrefix = check(currPrefix,vec[i]);
        return currPrefix;

    }
};
