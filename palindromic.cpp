#include <bits/stdc++.h>
using namespace std;

class GFG {
public:
  vector<vector<string> > ans;
  bool checkPalindrome(vector<string> currPartition)
  {
    for (auto s : currPartition) {
      int n = s.size();
      int i = 0, j = n - 1;
      while (i < j) {
        if (s[i] != s[j])
          return false;
        i++;
        j--;
      }
    }
    return true;
  }
  void generatePartition(string& s, string& bitString)
  {
    vector<string> currPartition;
    string subString;
    subString.push_back(s[0]);
    for (int i = 0; i < bitString.size(); i++) {
      if (bitString[i] == '0') {
        subString.push_back(s[i + 1]);
      }
      else {
        currPartition.push_back(subString);

        subString.clear();
        subString.push_back(s[i + 1]);
      }
    }
    currPartition.push_back(subString);
    if (checkPalindrome(currPartition)) {
      ans.push_back(currPartition);
    }
  }
  void bitManipulation(string& s, string& bitString)
  {
    if (bitString.size() == s.size() - 1) {
      generatePartition(s, bitString);
      return;
    }
    bitString.push_back('1');
    bitManipulation(s, bitString);
    bitString.pop_back();
    bitString.push_back('0');
    bitManipulation(s, bitString);
    bitString.pop_back();
  }
  vector<vector<string> > Partition(string s)
  {
    string bitString;
    bitManipulation(s, bitString);
    return ans;
  }
};

int main()
{
  GFG ob;
  vector<vector<string> > ans;
  string s = "geeks";
  ans = ob.Partition(s);
  for (auto& v : ans) {
    for (auto& it : v) {
      cout << it << " ";
    }
    cout << "\n";
  }
  return 0;
}
