class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
    int len = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    int pos;
    for(int i=0; i<len; i++) if(arr[i] == maxi) { pos = i; break; }
    if(len < 3) return false;
    else if(pos==0 or pos==len-1) return false;
    else
    {
        bool check = false;
        for(int i=pos; i>0; i--)
            if(arr[i] <= arr [i-1])
            {check = true; break;}

        if(check) return false;
        else
        {
            for(int i=pos; i<len-1; i++)
            if(arr[i] <= arr [i+1])
            {check = true; break;}

            if(check) return false;
            else return true;
        }
    }
    }
};
