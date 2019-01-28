function [f]=x5(N, xt)

for n=1:N
   f(n) = exp(-pi * xt(n)^2);
end

% figure(5);
% plot(xt, f);