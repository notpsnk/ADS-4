// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
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
      int l = left, r = right;
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int l_count = 1, r_count = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        ++l_count;
        ++left;
      }
      while (right - 1 > left && arr[right] == arr[right - 1]) {
        ++r_count;
        --right;
      }
      count += l_count * r_count;
      ++left;
      --right;
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
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int left = i + 1, right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    int pos = left;
    while (pos < len && arr[pos] == target) {
      ++count;
      ++pos;
    }
  }
  return count;
}
