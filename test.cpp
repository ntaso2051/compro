#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("test0.txt");
  // if (fout) cout << "file opened" << endl;
  int n, m;
  fin >> n >> m;
  fin.close();

  ofstream fout("test1.txt");
  fout << n << endl;
  fout << m << endl;
  fout.close();
}