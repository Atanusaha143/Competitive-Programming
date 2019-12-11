                                    // https://codeforces.com/contest/1064/problem/A

                                    #include<bits/stdc++.h>
                                    #define C char
                                    #define D double
                                    #define F float
                                    #define LL long long
                                    #define ULLI unsigned long long int
                                    #define LLI long long int
                                    #define LLD long long double
                                    #define LD long double
                                    #define S string
                                    #define PI (2.0*acos(0.0))
                                    #define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
                                    #define READ 		freopen("input.txt","r",stdin)
                                    #define WRITE  		freopen("output.txt","w",stdout)
                                    using namespace std;

                                    int main()
                                    {
                                        int arr[3];
                                        for(int i=0; i<3; i++) cin>>arr[i];
                                        sort(arr,arr+3,greater<int>());
                                        int x = arr[0]-(arr[1]+arr[2]);
                                        if(x<0) cout<<"0\n";
                                        else cout<<arr[0]-(arr[1]+arr[2])+1<<endl;
                                    }






