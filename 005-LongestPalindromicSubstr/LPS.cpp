class Solution {
public:
    void judgePalindrome(int left, int right, int str_len, string s, string &LStr, int &max){
        while(left >= 0 && right < str_len && s[left] == s[right]){
            left--;
            right++;
        }
        int len = right - left - 1;
        if(len > max){
            LStr = s.substr(left+1, len);
            max = len;
        }
    }

    string longestPalindrome(string s) {
        int str_len = s.size();
        if(str_len <= 2){
            return s;
        }
        int mid = str_len/2;
        string LStr;
        int left, right;
        int max_len = 0;
        while(mid + 1 < str_len){
            if(s[mid] == s[mid+1]){
                left = mid;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid++;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0){
            if(s[mid] == s[mid-1]){
                left = mid - 1;
                right = mid;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid--;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0 && mid + 1 <str_len){
            if(s[mid-1] == s[mid+1]){
                left = mid-1;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid--;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0 && mid + 1 <str_len){
            if(s[mid-1] == s[mid+1]){
                left = mid-1;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid++;
        }
        return LStr;
    }
};
