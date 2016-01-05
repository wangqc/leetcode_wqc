int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1){
            return 1;
        }
        int pSize = primes.size();
        vector<int> uglyNumber;
        uglyNumber.push_back(1);
        vector<int> indexes(pSize, 0);
        int count = 1;
        while(count < n){
            int uMin = INT_MAX;
            
            for(int i = 0; i < pSize; i++){
                uMin = min(uMin, primes[i] * uglyNumber[indexes[i]]);
            }
            uglyNumber.push_back(uMin);
            
            for(int i = 0; i < pSize; i++){
                if(uMin == uglyNumber[indexes[i]] * primes[i]){
                    indexes[i]++;
                }
            }
            count++;
        }
        return uglyNumber[n-1];
    }
