function [Fw]=tfour(vectf)

%tf	Transformée de Fourier discrète.
% 	tf(vectf) est la transformée de Fourier discrète de la fonction f
%       dont (ne) échantillons sont rangés dans le vecteur vectf. 
%	Ces échantillons correspondent à des "instants" centrés sur la 
%	valeur zéro. La valeur de f(0) doit être contenue dans 
%	l'échantillon (ne/2 + 1).
%
%  	Voir aussi tfi, IFFT, FFT2, IFFT2, FFTSHIFT.

tr=0;
if (size(vectf,2)==1)
    vectf=vectf';
    tr=1;
end

ne=size(vectf,2);
i=sqrt(-1);
nes2=ne/2;
Fw=fft(vectf);
Fw=fftshift(Fw);
temp=([1:ne]-(nes2-1))*pi;
Fw=exp(i*temp).*Fw;

if tr==1
    Fw=Fw';
end


