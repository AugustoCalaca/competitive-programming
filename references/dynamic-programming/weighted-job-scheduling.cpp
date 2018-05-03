#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
  int start;
  int finish;
  int profit;
};

int max(int a, int b) { return a > b ? a : b; }

bool compFinish(Job a, Job b) {
  return a.finish < b.finish;
}

// using linear search in pd, complexity n^2
int maxProfit(Job jobs[], int sz) {
  sort(jobs, jobs + sz, compFinish);

  int pd[sz], maxprofit;
  pd[0] = maxprofit = jobs[0].profit;

  for(int i = 1; i < sz; i++) {
    pd[i] = jobs[i].profit;
    for(int j = 0; j < i; j++) {
      // check if does overlap
      if(jobs[j].finish <= jobs[i].start) {
        pd[i] = max(pd[j] + jobs[i].profit, pd[i]);
        if(pd[i] > maxprofit) maxprofit = pd[i];
      }
    }
  }

  return maxprofit;
}
//

// using binary search in pd complexity nlogn
int binarySearch(Job jobs[], int k) {
  int left = 0, right = k - 1;

  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(jobs[mid].finish <= jobs[k].start) {
      if(jobs[mid + 1].finish <= jobs[k].start)
        left = mid + 1;
      else return mid;
    }
    else return right = mid - 1;
  }

  return -1;
}

int maxProfit2(Job jobs[], int sz) {
  sort(jobs, jobs + sz, compFinish);
  int pd[sz], maxprofit;
  pd[0] = maxprofit = jobs[0].profit;

  for(int i = 1; i < sz; i++) {
    pd[i] = jobs[i].profit;
    int find = binarySearch(jobs, i);
    if(find != -1) {
      pd[i] = max(pd[find] + jobs[i].profit, pd[i]);
      if(pd[i] > maxprofit) maxprofit = pd[i];
    }
  }

  return maxprofit;
}
//

int main() {
  Job jobs[] = { {1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2} };
  int sz = sizeof(jobs) / sizeof(jobs[0]);
  cout << "The optimal profit: " << maxProfit2(jobs, sz) << "\n";

  return 0;
}