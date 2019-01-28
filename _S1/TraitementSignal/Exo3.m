% DEFINE PARAMS %

N = 16384;
a = -5;
b = 5;
dp = 5;

% GET FREQUENCE & PERIODE %

te = (b - a) / N;
fe = 1 / te;

for n=1:N
   xt(n) = a + (n - 1) * te;
   xf(n) = (-fe / 2) + (n - 1) * (fe / N);
end

% c(t) 25/100 %

f = c(25, 100, N, xt, xf);

% figure(1)
% plot(xt, f)

% [fourier_f] = tfour(f);
% figure(1)
% plot(xf, fourier_f);

% d(t) %

f1 = d(f, 25, N, xt);
f2 = d(f, 100, N, xt);

[fourier_f1] = tfour(f1);
[fourier_f2] = tfour(f2);

figure(11)
subplot(2, 1, 1);
plot(xt, f1);
subplot(2, 1, 2);
plot(xf, fourier_f1);

figure(12)
subplot(2, 1, 1);
plot(xt, f2);
subplot(2, 1, 2);
plot(xf, fourier_f2);