/*
 given an array of unsorted integers, and a target,
 find consequtive subset, [i, j], s.t.
 the sume of a[i] + a[i+1] + ... + a[j] equals to
 target
*/

#include <utility>
#include <vector>
#include <map>
#include <iostream>

typedef std::pair<int, int> Pair;
typedef std::vector<Pair> VecPair;
typedef std::map<int, int> Tbl;

VecPair subsetSum(int a[], int n, int target){
  std::vector<int> sum(n);
  sum[0] = a[0];
  Tbl tbl;
  VecPair vp;
  for(int i = 1; i < n; ++i) {
    sum[i] = sum[i-1]+i;
    tbl[sum[i]] = i;
  }
  tbl[a[0]] = 0;
  for(Tbl::iterator it = tbl.begin();
       it!=tbl.end(); ++it) 
  {
    Tbl::iterator it2 = tbl.find(it->first + target);
    if (it2 != tbl.end())
    {
      std::cout << "found starting from "<< it->second+1 
        << " ends at "<< it2->second << std::endl;
      vp.push_back(std::make_pair(it->second+1, it2->second));
    }
  }
  return vp;
}

int main(){
  int a[7] = {-1, 4, 1, 0, -2, -3, 7};
  subsetSum(a, 7, 2);
}
