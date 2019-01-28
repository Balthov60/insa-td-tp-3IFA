% DEFINE PARAMS %

N = 16384;
a = -5;
b = 5;

% GET FREQUENCE & PERIODE %

te = (b - a) / N;
fe = 1 / te;

for n=1:N
   xt(n) = a + (n - 1) * te;
   xf(n) = (-fe / 2) + (n - 1) * (fe / N);
end

% Cons Function %

[vectCons] = x0(10, N, xt);
[consFour] = tfour(vectCons);

% figure(10);
% plot(xf, consFour);

% Cos Function %

[vectCos] = x1(3, N, xt);
[cosFour] = tfour(vectCos);
 
% figure(11); 
% plot(xf, cosFour);

% Sin Function %

[vectSin] = x2(1, N, xt);
[sinFour] = tfour(vectSin);
 
% figure(12);
% plot(xf, imag(sinFour));

% Dirak Function %

[vectDir] = x3(1, N, xt);
[dirFour] = tfour(vectDir);
 
% figure(13); 
% plot(xf, imag(dirFour));

% Exp Function %

[vectExp] = x4(5, N, xt);
[expFour] = tfour(vectExp);
 
% figure(14);
% subplot(3, 1, 1)
% plot(xt, vectExp);
% 
% subplot(3, 1, 2)
% plot(xf, expFour);
% 
% subplot(3, 1, 3)
% plot(xf, imag(expFour));

% Gaussienne %

[vectExp2] = x5(N, xt);
[exp2Four] = tfour(vectExp2);

figure(15)
subplot(3, 1, 1)
plot(xt, vectExp2);

subplot(3, 1, 2)
plot(xf, exp2Four);

[vectExp2Back] = tfourinv(exp2Four);

subplot(3, 1, 3)
plot(xt, vectExp2Back);

% Four et deFour %

% figure(16)
% subplot(3, 1, 1)
% plot(xt, vectCos);
% 
% subplot(3, 1, 2)
% plot(xf, cosFour);
% 
% [invExpCos] = tfourinv(cosFour);
% 
% subplot(3, 1, 3)
% plot(xt, invExpCos);

% periodique port %

% [vectPeriodPort] = periodPorte(0.2, 0.4, N, xt, a, b); 
% [fourierPeriodPort] = tfour(vectPeriodPort);
% 
% figure(17)
% subplot(2, 1, 1)
% plot(xt, vectPeriodPort);
% axis([-5, 5, -0.5, 1.5]);
% 
% subplot(2, 1, 2)
% plot(xf, fourierPeriodPort);
