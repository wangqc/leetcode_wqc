#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n) {
        if(n == 1){
            return 1;
        }
        vector<int> uglyNumber;
        uglyNumber.push_back(1);
        vector<int> indexes(3,0);
        vector<int> primes = {2,3,5};
        vector<int> L(3,0);
        int count = 1;
        while(count < n){
            for(int i = 0; i < 3; i++){
                L[i] = primes[i] * uglyNumber[indexes[i]];
            }
            uglyNumber.push_back(min(min(L[0], L[1]), L[2]));
            for(int i = 0; i < 3; i++){
                if(uglyNumber[count] == primes[i] * uglyNumber[indexes[i]]){
                    indexes[i]++;
                }
            }
            count++;
        }
        return uglyNumber[n-1];
}


int main(){
	int n;
	cin >> n; 
	cout << nthUglyNumber(n) << endl;
}
