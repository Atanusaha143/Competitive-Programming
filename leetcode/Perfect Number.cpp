class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector <int> divisors;
        if(num == 1) return false;
        else
        {
            int limit = sqrt(num);
            for(int i=2; i<=limit; i++)
            {
                if(i*i == num) divisors.push_back(i);
                else if(num%i ==0)
                {
                    divisors.push_back(i);
                    divisors.push_back(num/i);
                }
            }

            long long sum = 0;
            for(int i=0; i<divisors.size(); i++) sum += divisors[i];
            sum++;
            if(sum == num) return true;
            else return false;
        }
    }
};
