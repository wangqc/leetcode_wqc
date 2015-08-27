#include<iostream>
#include<vector>
#include<complex>

using namespace std;

int countPrimes(int n) {
        vector<bool> primes(n, true);
        if(n<=2){
            return 0;
        }
        for(int i=4; i<n; i+=2){
            primes.at(i) = false;
        }
        int middle = sqrt(n);
        cout << middle << endl;
        for(int i=3; i<=middle; i+=2){
            if(primes[i]){
                cout << i << endl;
                for(int j=i*i;j<n;j+=2*i){
                    primes.at(j) = false;
                    cout << j<< " ";
                }
            }
        }
        cout << endl;
        int cnt = 1;
        for(int i=3; i<n; i+=2){
            if(primes[i]){
                cnt++;
                cout << i << " ";
            }
        }
        cout << endl;
        return cnt;
}

int main(){
    int num;
    cin >> num;
    countPrimes(num);
}
