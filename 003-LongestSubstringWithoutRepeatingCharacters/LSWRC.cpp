    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0){
            return 0;
        }
        int start = 0;
        int end = 0;
        int max = 0;
        int count = 0;
        int offset = 0;
        vector<int> char2index(256, -1);
        for(int i = 0; i < size; i++){
            if(char2index[s[i]] != -1){
                end = char2index[s[i]];
                for(int j = start; j<=end; j++){
                    char2index[s[j]] = -1;
                }
                if(count > max){
                    max = count;
                }
                offset = end - start + 1;
                count = count - offset;
                start = end + 1;
            }
            char2index[s[i]] = i;
            count ++;
        }
        if(count > max){
            max = count;
        }
        return max;
    }
