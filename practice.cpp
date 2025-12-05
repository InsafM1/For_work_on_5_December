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
  size_t points(const IDraw& d, p_t ** pts, size_t& s);
  f_t frame(const p_t * pts, size_t s);
}
int main()
{
  using topit::p_t;
  using topit::Dot;
  using topit::f_t;
  int err = 0;
  IDraw* shps[3] = {}; //несколько раз подряд new нельзя!
  p_t * ptr = nullptr;
  size_t s;  
  try {
    shps[0] = new Dot(0, 0);
    shps[1] = new Dot(5, 7);
    shps[2] = new Dot(-5, -2);
    //TODO:
    for (sizet i = 0; i < 3; ++i){
      s += points(*(shps[i], &pts, s));
    }
    f_t fr = frame(pts, s);
    // достать все точки из фигур
    // посчитать ограничивающий прямоугольник
    // подготовить полотно () нужнго размера
    // заполнить полотно .
    // нароисовать на полотне все точки
    // - будем рисовать #
    // вывести полотно на экран
  } catch (...) {
    err = 2;
    std::cerr << "Bad Drawing\n";
  }
  delete [] ptr;
  for (int i = 0; i < 3; ++i){
    delete shps[i];
  }
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
