#include <iostream>
#include "week1/Vector.h"
#include "week1/List.h"
using namespace std;
int main() {
  List<int> a;
  a.append(1);
  a.append(2);
  a.append(3);
  a.append(4);
  a.append(5);
  List<int> b;
  b.append(1);
  b.append(5);
  auto c = a.merge(b);
  cout<<c.size()<<endl;

  for(int i = 0; i < c.size(); ++ i){
    cout<<c[i]<<endl;
  }
  return 0;
}
