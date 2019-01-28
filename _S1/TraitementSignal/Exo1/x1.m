function [f]=x1(p, N, xt)

for n=1:N
   f(n) = cos(2 * pi * p * xt(n));
end

% figure(1);
% plot(xt, f);