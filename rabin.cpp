#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(const string &txt, const string &pat) {
    vector<int> result;
    int N = txt.size();
    int M = pat.size();
    if (M == 0 || N < M) return result;

  const int d = 256;
  const int q = 101;

  long long h = 1;
  for (int i = 0; i < M - 1; i++)
    h = (h * d) % q;

  long long p = 0;
  long long t = 0;
  for (int i = 0; i < M; i++) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  for (int i = 0; i <= N - M; i++) {
    if (p == t) {
      bool match = true;
      for (int j = 0; j < M; j++) {
        if (txt[i + j] != pat[j]) {
          match = false;
          break;
        }
      }
      if (match)
        result.push_back(i + 1);
    }

    if (i < N - M) {
      t = (d * (t - txt[i] * h) + txt[i + M]) % q;
      if (t < 0)
        t += q;
    }
  }

  return result;
}
