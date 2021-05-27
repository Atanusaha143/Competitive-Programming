class Solution {
public:
    int countPrimes(int n) {
    int x = 5e6+10;
    bool prime[x];
    memset(prime,true,sizeof(prime));
    int limit = sqrt(x);
    prime[0] = false;
    prime[1] = false;
    for(int i=4; i<x; i+=2) prime[i] = false;
    for(int i=3; i<=limit; i+=2)
    {
        if(prime[i])
        {
            for(int j=i*i; j<x; j+=i*2)
            {
                prime[j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
        if(prime[i])
            cnt++;
    return cnt;
    }
};
