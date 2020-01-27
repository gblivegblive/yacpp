int Factorial(int x) {
  int result = 1;
  if (x <= 0) {
    return 1;
  }
  else {
    for (int i=1; i<=x; i++){
      result = result * i;
    }
  }
  return result;
}
