function [f]=c(p1, p2, N, xt, xf)

s1R = s1(N, xt);
s1R_F = tfour(s1R);

s2R = s2(N, xt);
s2R_F = tfour(s2R);

% figure(1)
% subplot(2, 1, 1);
% plot(xt, s1R);
% subplot(2, 1, 2);
% plot(xf, s1R_F);
% 
% figure(2)
% subplot(2, 1, 2);
% plot(xt, s2R);
% subplot(2, 1, 2);
% plot(xf, s2R_F);

for n=1:N
   f(n) = s1R(n) * cos(2 * pi * p1 * xt(n)) + s2R(n) * cos(2 * pi * p2 * xt(n));
end