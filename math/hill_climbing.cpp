for (s = 1; s > 1e-6; f = 0)
{
  if (F(dx, dy) > F(dx + s, dy)) dx += s, f = 1;
  else if (F(dx, dy) > F(dx - s, dy)) dx -= s, f = 1;
  else if (F(dx, dy) > F(dx, dy + s)) dy += s, f = 1;
  else if (F(dx, dy) > F(dx, dy - s)) dy -= s, f = 1;
  if (!f) s *= 0.7;
}
