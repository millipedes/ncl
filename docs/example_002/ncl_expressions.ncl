canvas(height(1080), width(1920), color(0, 0, 0)) {
  for i in range(24) {
    for j in range(15) {
      p = point(40.0 * i + 40.0, 40.0 * j + 40.0)
      rect = rectangle(point(80.0 * i + 40.0, 80.0 * j + 40.0),    \
                       color(j * (255 / 12), 255, i * (255 / 12)), \
                       height(50.0),                               \
                       width(50.0),                                \
                       thickness(5.0)                              \
                      )
      ellip = ellipse(point(80.0 * i + 40.0, 80.0 * j + 40.0),    \
                      color(j * (255 / 12), 255, i * (255 / 12)), \
                      minor_axis(50.0),                           \
                      major_axis(50.0),                           \
                      thickness(5.0)                              \
                     )
      l = line(from(rect), to(p), color(0, 35, 66), thickness(5))
      pivot = 10.0
      if((i > pivot) || (i < 2)) {
        write(ellip)
      }
      if(i < pivot) {
        if(j >= pivot) {
          write(rect)
        }
      }
    }
  }
}
