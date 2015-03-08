#include <vector>

int main() {
  for(int k = 0;k < 1024;k++){
    std::vector<int> ary(10);
    for(int i = 0;i < 10000;i++){
      int c = 0;
      for(int j = 0;j < ary.size();j++){
        if(ary[j] == 0) c++;
      }
    }
  }

  return 0;
}
