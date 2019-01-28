function [f]=x2(p, N, xt)

for n=1:N
   f(n) = sin(2 * pi * p * xt(n));
end

% figure(2);
% plot(xt, f);