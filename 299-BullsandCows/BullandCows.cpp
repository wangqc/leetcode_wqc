class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> sv(10, 0);
        vector<int> gv(10, 0);
        int size = secret.size();
        int bull = 0;
        int cow = 0;
        string res;
        for(int i = 0; i < size; i++){
            if(secret[i] == guess[i]){
                bull++;
            }
            else{
                sv[secret[i]-'0']++;
                gv[guess[i]-'0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            cow += min(sv[i], gv[i]);
        }
        res = to_string(bull) + "A" + to_string(cow) + "B";
        return res;
    }
};
