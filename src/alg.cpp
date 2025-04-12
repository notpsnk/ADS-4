// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
      else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len;
  while (left < right) {
    int s = arr[left] + arr[right];
    if (s == value) {
      ++count;
      ++left;
      --right;
    }
    else if (s < value) {
      ++left;
    }
    else {
      --right;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int x = value - arr[i];
    int left = i, right = len;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == x) {
        ++count;
        break;
      }
      else if (arr[mid] < x) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
  }
  return count;
}
