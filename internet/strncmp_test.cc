#include <stdio.h> 
#include <cstring>

class Base{
public:
  virtual void func() {printf ("print from base \n"); };
};

template<class Base>
class Mix : private Base
{
  public:
  void func()
  {
    Base::func();
  }
};


int main(){
  Base b();
  Mix<Base> m;
  m.func();
}
