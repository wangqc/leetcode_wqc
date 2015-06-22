string longestCommonPrefix(vector<string>& strs){
    string newStr;
    int length = strs.size();
    if(length == 0){
        return "";
    }
    else if(length == 1){
        return strs.at(0);
    }
    else{
        newStr = strs.at(0);
        int sub_len;
        int cur_len;
        for(int i = 1; i < length; i++) {
            sub_len = newStr.size();
            cur_len = strs.at(i).size();
            int j = 0;
            for(; j < sub_len && j < cur_len; j++){
                if(newStr.at(j) != (strs.at(i)).at(j)){
                    if(j == 0){
                        return "";
                    }
                    else{
                        newStr = newStr.substr(0, j);
                    }
                    break;
                }
            }
            if(j < sub_len){
                newStr = newStr.substr(0, j);
            }
        }
    }
    return newStr;
}
