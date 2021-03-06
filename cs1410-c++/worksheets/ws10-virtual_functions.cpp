#include <iostream>
using namespace std;

class A {};                      // Base class 1
class B {};                      // Base class 2
class C : public A, public B {}; // Derived class from A and B

// TODO
class Employee {};
class Student {};
class Manager : public Employee, public Student {};
class Scientist : public Employee, public Student {};

class Parent {
public:
  void foo() {}
};

class Child1 : public Parent {
public:
  void bar() {}
};

class Child2 : public Parent {};

class GrandChild : public Child1, public Child2 {};

/*
GrandChild d;
d.foo();
*/

class AnotherParent {
public:
  void foo() {}
};

class AnotherChild1 : virtual public AnotherParent {
public:
  void bar() {}
};

class AnotherChild2 : virtual public AnotherParent {};

class AnotherGrandChild : public AnotherChild1, public AnotherChild2 {};

class Base {
public:
  void show() { cout << "Base\n"; }
};

class Derived1 : public Base {
public:
  void show() { cout << "Derived 1\n"; }
};

class Derived2 : public Base {
public:
  void show() { cout << "Derived 2\n"; }
};

// TODO
class BaseClass {};
class DerivedClass1 : virtual public BaseClass {};
class DerivedClass2 : virtual public BaseClass {};
class DerivedFurtherClass1 : public DerivedClass1, public DerivedClass2 {};
class DerivedFurtherClass2 : public DerivedClass1, public DerivedClass2 {};

class AnotherBase {
public:
  virtual void show() { cout << "Another Base\n"; }
  virtual ~AnotherBase() {} // Virtual destructor
};

class AnotherDerived1 : public AnotherBase {
public:
  void show() { cout << "Another Derived 1\n"; }
};

class AnotherDerived2 : public AnotherBase {
public:
  void show() { cout << "Another Derived 2\n"; }
};

// TODO: The Rectangle class
class Rectangle {
private:
  int x, y, width, height;

public:
  Rectangle(int x, int y, int width, int height)
      : x(x), y(y), width(width), height(height) {}
  virtual string getName() { return "Rectangle"; }
  virtual ~Rectangle() {}
};

// TODO: The Square class
class Square : public Rectangle {
private:
  int x, y, length;

public:
  Square(int x, int y, int length) : Rectangle(x, y, length, length) {}
  virtual string getName() { return "Square"; }
};

class SomeClass {
public:
  virtual void print() = 0; // a pure function
};

int main(int argc, char const* argv[]) {
  GrandChild gc;
  gc.Child2::foo();

  AnotherGrandChild d2;
  d2.foo();

  Derived1 d1;
  Derived2 d2_1, d2_2;

  d1.show();
  d2_1.show();
  d2_2.show();

  Base* bptr;
  bptr = &d1;
  bptr->show();
  bptr = &d2_1;
  bptr->show();

  Base& bref = d2_2;
  bref.show();

  AnotherDerived1 ad1;
  AnotherDerived2 ad2_1, ad2_2;

  ad1.show();
  ad2_1.show();
  ad2_2.show();

  AnotherBase* abptr;
  abptr = &ad1;
  abptr->show();
  abptr = &ad2_1;
  abptr->show();

  AnotherBase& abref = ad2_2;
  abref.show();

  return 0;

  // TODO
  Rectangle r(0, 0, 10, 20);
  Square s(0, 0, 10);

  Rectangle* rptr = nullptr;
  rptr = &r;
  cout << rptr->getName() << endl;
  rptr = &s;
  cout << rptr->getName() << endl;

  // TODO
  Rectangle r2(0, 0, 10, 20);
  Square s2(0, 0, 10);

  Rectangle& rref = s2;
  cout << rref.getName() << endl;

  // Not allowed, because `SomeClass` becomes abstract with the addition of a
  // pure virtual function:

  // SomeClass sc;
}