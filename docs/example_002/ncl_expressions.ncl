canvas(height(10), width(1000)) {
  a = -1
  a = 2 + 3 - 15
  a = 2.0 + 3.0 - 15.0
  b = color(1, 3, 2)
  c = point(2.0, 3.0)
  d = rectangle(point(3.0 + 10.0, 19.0 - 10.0), \
                height(4),                      \
                width(5),                       \
                color(0, 23, 42),               \
                thickness(42)                   \
               )
  e = rectangle()
  f = ellipse(point(3.0 + 10.0, 19.0 - 10.0),   \
                major_axis(4),                  \
                minor_axis(5),                  \
                color(0, 23, 42),               \
                thickness(42)                   \
               )
  g = ellipse()
  h = line(to(rectangle(point(3.0 + 10.0, 19.0 - 10.0), height(4), width(5), color(0, 23, 42), thickness(42))), from(ellipse()), thickness(19), color(0, 23, 42))
  i = line()
}
