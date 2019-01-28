function [f]=s1(N, xt)

for n=1:N
   f(n) = cos(2 * pi * 2 * xt(n)) + cos(2 * pi * 4 * xt(n)) + cos(2 * pi * 6 * xt(n)) + cos(2 * pi * 8 * xt(n)) + cos(2 * pi * 10 * xt(n));
end