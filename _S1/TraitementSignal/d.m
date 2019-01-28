function [f]=d(ct, p, N, xt)

for n=1:N
   f(n) = ct(n) * cos(2 * pi * p * xt(n));
end