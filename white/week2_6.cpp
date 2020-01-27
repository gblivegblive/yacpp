void Reverse(vector<int> &v) {
  vector<int> temp(v.rbegin(), v.rend());
  v = temp;
}
