function [f]=s2(N, xt)

for n=1:N
   f(n) = 5 * cos(2 * pi * 2 * xt(n)) + 4 * cos(2 * pi * 4 * xt(n)) + 3 * cos(2 * pi * 6 * xt(n)) + 2 * cos(2 * pi * 8 * xt(n)) + cos(2 * pi * 10 * xt(n));
end