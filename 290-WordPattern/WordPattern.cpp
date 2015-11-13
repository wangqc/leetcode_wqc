#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string str) {
  map<char, string> wPattern;
  string::iterator it;
  istringstream record(str);
  string word;
  set<string> existword;
  for(it = pattern.begin(); it != pattern.end(); it++){
    cout << "char " << *it << endl;
    if(!(record >> word)){
      cout << "Inside word :" << word << endl;
      cout << "no word to match!!!" << endl;
      return false;
    }
    cout << "word " << word << endl;
    if(wPattern.find(*it) == wPattern.end()){
      if(existword.find(word) != existword.end()){
        return false;
      }
      else{
        wPattern[*it] = word;
      }
    }
    else{
      if(wPattern[*it] != word){
        return false;
      }
    }
    existword.insert(word);
  }
  return true;
}


int main(){
  string pattern, str;
  getline(cin, str);
  cin >> pattern;
  if(wordPattern(pattern, str)){
    cout << "It is map!!" << endl;
  }
  else{
    cout << "Fuck!!!"  << endl;
  }
}
