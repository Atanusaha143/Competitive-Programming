#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1000006;
int n, m;
bool prime[N+5];
int mobius[N+5];

void generateMobius()
{
    for(int i=1; i<=N; i++){
        mobius[i] = 1;
    }
    for(int i=2; i<=N; i++){
        if(!prime[i]){
            mobius[i] *= -1;
            for(int j=i+i; j<=N; j+=i){
                if(j % (i*i) == 0){
                    mobius[j] *= 0;
                }
                else{
                    mobius[j] *= -1;
                }
                prime[j] = 1;
            }
        }
    }
}

void solve(int tt)
{
    cin>>n>>m;
    if(n == 0 and m == 0){
        cout<<"Case "<<tt<<": 0"<<endl;
    }
    else if(n == 0 and m != 0){
        cout<<"Case "<<tt<<": 1"<<endl;
    }
    else if(n != 0 and m == 0){
        cout<<"Case "<<tt<<": 1"<<endl;
    }
    else{
        ll all_pairs = 1ll * n * m;
        all_pairs += 2; // with x = 0 and y = 0;
        ll pairs_without_gcd1 = 0;
        for(int i=2; i<=(int)min(n,m); i++){
            ll pairs_with_gcd_i = 1ll * (n / i) * (m / i) * mobius[i];
            pairs_without_gcd1 += pairs_with_gcd_i;
        }
        ll pairs_with_gcd1 = all_pairs + pairs_without_gcd1;
        cout<<"Case "<<tt<<": "<<pairs_with_gcd1<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    generateMobius();
    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
    }
}

/*
Link : https://lightoj.com/problem/ray-gun

Sol : The problem is basically the count of co-prime pairs which can be made with till N and M numbers.
If we observe closely we can see that,
From point (0,0) if we draw a straight line by intersecting point (1,1) - the line intersects
(1,1), (2,2), (3,3), (4,4), which are basically same as first intersecting point if we divide the
pair with their GCD. Then we get -
(1,1) / GCD(1,1) = (1,1)
(2,2) / GCD(2,2) = (1,1)
(3,3) / GCD(3,3) = (1,1)
(4,4) / GCD(4,4) = (1,1)
From point (0,0) if we draw a straight line by intersecting point (1,2) - the line intersects
(1,2), (2,4), (3,6), (4,8), which are basically same as first intersecting point if we divide the
pair with their GCD. Then we get -
(1,2) / GCD(1,1) = (1,2)
(2,4) / GCD(2,4) = (1,2)
(3,6) / GCD(3,6) = (1,2)
(4,8) / GCD(4,8) = (1,2)
From point (0,0) if we draw a straight line by intersecting point (1,3) - the line intersects
(1,3), (2,6), (3,9), (4,12), which are basically same as first intersecting point if we divide the
pair with their GCD. Then we get -
(1,3) / GCD(1,1) = (1,3)
(2,6) / GCD(2,6) = (1,3)
(3,9) / GCD(3,9) = (1,3)
(4,12) / GCD(4,12) = (1,3)
So, the points we are getting are Co-Primes. Excluding these points the remaining points will also
be Co-Primes numbers.
So, we have to find out how many unique Co-Prime pairs we can get from the given limit, where Co-Primes
pair means that they have GCD = 1;
We know there are total (N*M) points and from that if we subtract the points whose don't have
a GCD = 1, we can get how many unique Co-Prime pairs have GCD = 1
*/
