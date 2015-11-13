#include <iostream>
#include <vector>
#include <string>

using namespace std;



void backtrace(vector<string> &res, const vector<char> &paren, string &solu, int n, int x, int y){
	cout << "Enter the func " << to_string(x) << ", " << to_string(y) << ", " << endl; 
	if(solu.size() == 2*n){
		res.push_back(solu);
		return;
	}
	else{
		for(int i = 0; i < 2; i++){
			if(paren[i] == '('){
				if(x == n){
					continue;
				}
				else{
					solu.push_back('(');
					backtrace(res, paren, solu, n, x+1, y);
					solu.pop_back();
				}
			}
			else{
				if(x == y){
					return;
				}
				else{
					solu.push_back(')');
					backtrace(res, paren, solu, n, x, y+1);
					solu.pop_back();
				}
			}
		}
	}
	return;
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	if(n == 0){
		return res;
	}
	vector<char> paren{'(', ')'};
	string solu = "(";
	int x = 1;
	int y = 0;
	backtrace(res, paren, solu, n, x, y);
	return res;
}

int main(){
	vector<string> test;
	int n;
	cout << "Please input the num:";
	cin >> n;
	test = generateParenthesis(n);
	for(auto iter = test.begin(); iter != test.end(); ++iter){
		cout << *iter << endl;
	}
	return 0;
}
