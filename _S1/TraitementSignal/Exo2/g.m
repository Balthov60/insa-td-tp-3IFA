function [f]=g(p, dp, N, xt)

for n=1:N
   f(n) = sin(2 * pi * p * xt(n)) + sin (2 * pi * (p + dp) * xt(n)) + 2 * sin(2 * pi * (p + 3 * dp) * xt(n));
end

figure(1); 
plot(xt, f);