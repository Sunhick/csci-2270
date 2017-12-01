/**
 * main.cpp - Demonstrates the use of virtual destructor.
 * Note: There's no virtual constructor.
 *
 * Copyright (C) 2017 by Sunil
 */
#include <iostream>

using std::cout;
using std::endl;

namespace demo {

class Foo {
 public:
  Foo();
   virtual ~Foo();
};  // class Foo

// final keywords marks class can't be inherited.
class Bar final : public Foo {
 public:
  Bar();
   ~Bar();
};  // class Bar

// Error : Foobar can't extend final class.
// class Foobar : Bar {
//  public:
//   Foobar();
//   virtual ~Foobar();
// }; // class Foobar


Foo::Foo() {
  cout << "Foo ctor" << endl;
}

Foo::~Foo() {
  cout << "Foo dtor" << endl;
}

Bar::Bar() {
  cout << "Bar ctor" << endl;
}

Bar::~Bar() {
  cout << "Bar dtor" << endl;
}

}  // namespace demo

int main(int argc, char *argv[argc]) {

  using namespace demo;
  
  // comment out virtual dtor in Foo to see the what happens
  // without virtual dtor, calling delete from base ptr will
  // NOT call derived type dtor.
  Foo* f = new Bar;
  delete f;
  
  return 0;
}
