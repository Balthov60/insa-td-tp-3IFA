function [f]=x4(p, N, xt)

for n=1:N
   f(n) = exp(i * 2 * pi * p * xt(n));
end

% figure(4);
% plot(xt, f);