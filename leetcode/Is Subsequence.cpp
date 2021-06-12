class Solution {
public:
    bool check(string s1, string s2, int len1, int len2)
    {
        if(len1 == 0) return true;
        if(len2 == 0) return false;

        if(s1[len1-1] == s2[len2-1]) return check(s1,s2,len1-1,len2-1);
        return check(s1,s2,len1,len2-1);
    }
    bool isSubsequence(string s1, string s2) {
        bool ans = true;
        if(s1.size()>s2.size()) ans = false;
        else ans = check(s1,s2,s1.size(),s2.size());
        return ans;
    }
};
