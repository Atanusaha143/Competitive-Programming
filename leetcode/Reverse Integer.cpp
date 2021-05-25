class Solution {
public:
    int reverse(int x) {
        stringstream sso;
        sso << x;
        string s;
        sso >> s;
        string news;
        int till = 0;
        for(int i=s.size()-1; i>=0; i--)
            if(s[i]-'0'!=0) {till = i; break;}
        for(int i=0; i<=till; i++) news += s[i];

        if(news[0] == '-')
        {
            for(int i=1; i<(news.size()/2)+1; i++)
                swap(news[i], news[news.size()-i]);
        }
        else
        {
            for(int i=0; i<news.size()/2; i++)
                swap(news[i], news[news.size()-i-1]);
        }
        stringstream ss;
        ss << news;
        long long num = 0;
        ss >> num;
        if(num >= INT_MIN and num <= INT_MAX) return num;
        else return 0;
    }
};
