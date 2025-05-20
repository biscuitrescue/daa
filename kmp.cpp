#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(const string &pat) {
  int m = pat.size();
  vector<int> lps(m, 0);
  int len = 0, i = 1;
  while (i < m) {
    if (pat[i] == pat[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i++] = 0;
      }
    }
  }
  return lps;
}

vector<int> KMPSearch(const string &txt, const string &pat) {
  int n = txt.size(), m = pat.size();
  vector<int> lps = computeLPS(pat);
  vector<int> result;
  int i = 0, j = 0;
  while (i < n) {
    if (txt[i] == pat[j]) {
      i++; j++;
    }
    if (j == m) {
      result.push_back(i - j + 1);
      j = lps[j - 1];
    } else if (i < n && txt[i] != pat[j]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return result;
}

int main() {
  string txt = "AABAACAADAABAABA";
  string pat = "AABA";
  vector<int> indices = KMPSearch(txt, pat);
  for (int idx : indices) {
    cout << "Pattern found at index " << idx << endl;
  }
  return 0;
}
