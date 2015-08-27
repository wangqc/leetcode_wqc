int countPrimes(int n) {
        vector<int> prime;
        prime.push_back(2);
        int size = 1;
        bool toAdd = false;
        if(n<2){
            return 0;
        }
        else if(n==2){
            return 1;
        } 
        else{
            for(int i = 3; i <=n; i++){
                toAdd = true;
                for(int j=0;j<size;j++){
                    if(i%(prime.at(j))==0){
                        toAdd = false;
                        break;
                    }
                }
                if(toAdd){
                    prime.push_back(i);
                    size++;
                }
            }
        }
        return size;
}
