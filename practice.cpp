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
}
int main()
{
  using topit::p_t;
  p_t a{1, 0}, b{1, 0};
  std::cout << (a == b) << '\n';

  
}

bool topit::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool topit::operator!=(p_t a, p_t b)
{
  return !(a == b);
}
