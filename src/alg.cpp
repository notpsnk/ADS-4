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
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int l = left;
      int r = right;
      while (l < r && arr[l] + arr[r] == value) {
        ++count;
        ++l;
      }
      --right;
    } else if (sum < value) {
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
    int low = left;
    left = i + 1;
    right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    int high = right;
    if (low <= high) {
      count += (high - low + 1);
    }
  }
  return count;
}
