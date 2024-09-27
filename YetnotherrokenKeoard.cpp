#include<bits/stdc++.h>
        using namespace std;
         
        //Number Theory Templates
        bool ISPRIME(long long N){
            if(N <= 1){
                return false;
            }
            for(int i = 2; i * i <= N; ++i){
                if(N % i == 0){
                    return false;
                }
            }
            return true;
        }
        vector<long long> FACTORIZATION(long long N){
            long long X = N;
            vector<long long> ANS;
            for(int i = 2; i * i <= N; ++i){
                while(X % i == 0){
                    ANS.push_back(i);
                    X/=i;
                }
            }
            if(X != 1){
                ANS.push_back(X);
            }
            return ANS;
        }
        long long BINOMIAL(int n, int k){
            if(k > n){
                return 0;
            }
            if(k == 1 || k == n){
                return 1;
            }
            return BINOMIAL(n-1, k-1) + BINOMIAL(n-1, k);
        }
        vector<long long> DIVISORS(long long N){
            vector<long long> ANS;
            for(int i = 1; i * i < N; ++i){
                if(N % i == 0){
                    ANS.push_back(i);
                    if(i * i != N){
                        ANS.push_back(N/i);
                    }
                }
            }
            return ANS;
        }
        vector<int> SIEVE(int N){
            vector<int> p;
            bool b[N+7];
            for(int i = 2; i < N+7; ++i){
                b[i]=false;
            }
            for(int i = 2; i < N+7; ++i){
                if(!b[i]){
                    p.push_back(i);
                    for(int j = 2*i; j < N+7; j+=i){
                        b[j] = true;
                    }
                }
            }
            return p;
        }
        //Geometry Templates
        struct POINT{
            long long x, y;
        };
        double EUCLDIST(POINT A, POINT B){
            return sqrt((abs(A.x - B.x))*(abs(A.x - B.x))+(abs(A.y - B.y))*(abs(A.y - B.y)));
        }
        double MANHATTDIST(POINT A, POINT B){
            return abs(A.x - B.x) + abs(A.y - B.y);
        }
         
        //3d Geometry
        struct POINT3D{
            long long x, y, z;
        };
        double EUCLDIST3D(POINT3D A, POINT3D B){
            return sqrt((abs(A.x - B.x))*(abs(A.x - B.x))+(abs(A.y - B.y))*(abs(A.y - B.y))+(abs(A.z - B.z))*(abs(A.z - B.z)));
        }

    void solve(){
        string str; cin >> str;
        vector<pair<char, int>> STACK1;
        vector<pair<char, int>> STACK2;
        int i = 0;
        for(char c : str){
            if(c != 'b' && c != 'B'){
                if(c > 96){
                    STACK2.push_back({c, i});
                }
                else{
                    STACK1.push_back({c, i});
                }
                ++i;
            }
            else if(c == 'b'){
                if(!STACK2.empty()){
                    STACK2.pop_back();
                }
            }
            else{
                if(!STACK1.empty()){
                    STACK1.pop_back();
                }
            }
        }
        int l = 0, p = 0;
        for(int j = 0; j < STACK1.size()+STACK2.size(); ++j){
            if(l < STACK1.size()){
                if(p < STACK2.size()){
            if(STACK1[l].second <  STACK2[p].second){
                cout << STACK1[l].first;
                l++;
            }
            else{
                cout << STACK2[p].first;
                p++;
            }
                }
                else{
                cout << STACK1[l].first;
                l++;
            }
            }
            else{
                cout << STACK2[p].first;
                p++;
            }
        }
        cout << "\n";
    }
         
    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        int T = 1; cin  >> T;
        while(T--){
            solve();
        }
    }
