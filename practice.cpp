#include <iostream>
namespace topit
{
  struct p_t { int x, y; };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct IDraw {
    virtual p_t begin() const = 0; // = 0 метод чисто виртуальный, мы не предоставляем метод
    virtual p_t next(p_t) const = 0;
    virtual ~IDraw() = default;
  };
  struct f_t { p_t aa, bb; };
  struct Dot: IDraw {
    Dot(int x, int y);
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d; 
  };
}
int main()
{
  using topit::p_t;
  IDraw * p = new Dot(10, 10);
  IDraw * p = new Dot(p_t{10, 10});
  delete p;
  delete pp;
}
topit::Dot::Dot(p_t dd): IDraw(), d{dd}
{}

bool topit::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool topit::operator!=(p_t a, p_t b)
{
  return !(a == b);
}

topit::p_t topit::Dot::begin() const 
{
  return d;
}

topit::p_t topit::Dot::next(p_t prev) const 
{
  if (prev != begin){
    throw std::logic_error("bad impl"); 
  }
  return d;
}

topit::Dot::Dot(int x, int y):
 Idraw();
 d{x, y}
{}
