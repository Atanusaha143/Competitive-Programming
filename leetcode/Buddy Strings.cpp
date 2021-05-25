class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size() != b.size()) return false;
    else
    {
        set <char> st;
        for(int i=0; i<a.size(); i++) st.insert(a[i]);
        if(a==b and st.size() < a.size()) return true;
        else
        {
            vector <int> vec;
            for(int i=0; i<a.size(); i++)
                if(a[i]!=b[i])
                    vec.push_back(i);

            if(vec.size() == 2 and a[vec[0]] == b[vec[1]] and b[vec[0]] == a[vec[1]]) return true;
            else return false;
        }
    }
    }
};
