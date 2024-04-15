# Hello Canvas
This is the first example of how to use ncl. Here is the source code for this
example:

```
canvas(height(1080), width(1920), color(0, 255, 0)) {
}
```

Let's break it down. ncl files will revolve around a canvs which has certain
parameters which are required to construct:
  - height: The height of the canvas in pixels (must be an integer value).
  - width: The width of the canvas in pixels (must be an integer value).
  - color: The color which the canvas will be filled with.

In this language, there are 2d primitives which are parameterized but have
initial sensible defaults.  For this reason, the order of parameters of canvas
are optional and not order sensitive.

We can see that this changed the parameters of the canvas by running:

```
canvas() {
}
```
which is valid and will yield a 1000x1000 png with color (0, 35, 66).
