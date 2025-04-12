// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int s = arr[left] + arr[right];
    if (s == value) {
      ++count;
      int leftVal = arr[left], rightVal = arr[right];
      while (left < right && arr[left] == leftVal) ++left;
      while (left < right && arr[right] == rightVal) --right;
    } else if (s < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int x = value - arr[i];
    int left = i + 1, right = len - 1;
    int f = 0;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == x) {
        f = 1;
        break;
      } else if (arr[mid] < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (f) {
      if (x == arr[i]) {
        continue;
      }
      count++;
    }
  }
  return count;
}
