% DEFINE PARAMS %

N = 16384;
a = -5;
b = 5;
dp = 5;

% GET FREQUENCE & PERIODE %

te = (b - a) / N;
fe = 1 / te;

% p = 400 %

[g1] = g(400, dp, N, xt);
[tfg1] = tfour(g1);

figure(10)
subplot(2, 1, 1)
plot(xt, g1);

subplot(2, 1, 2)
plot(xf, imag(tfg1));

% p = 1200 %

[g2] = g(1200, dp, N, xt);
[tfg2] = tfour(g2);

figure(11)
subplot(2, 1, 1)
plot(xt, g2);

subplot(2, 1, 2)
plot(xf, imag(tfg2));

