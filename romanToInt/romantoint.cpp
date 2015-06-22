int romanToInt(string s){
    map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    
    const int len = s.size();
    int sum = 0;
    int tmp_sum;
    bool to_judge = false;
    char pre_char = s.at(0);
    for(int i = 0; i < len; i++){
        if(roman[pre_char] < roman[s.at(i)]){
            if(to_judge){
                sum = tmp_sum + roman[s.at(i)] - roman[pre_char];
                to_judge = false;
            }
            else{
                sum = roman[s.at(i)] - sum;
            }
        }
        else if(roman[pre_char] > roman[s.at(i)]){
            tmp_sum = sum;
            sum += roman[s.at(i)];
            to_judge = true;
        }
        else{
            sum += roman[s.at(i)];
        }
        pre_char = s.at(i);
    }
    return sum;

}
