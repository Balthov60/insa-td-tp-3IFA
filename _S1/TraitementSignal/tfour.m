function [Fw]=tfour(vectf)

%tf	Transform�e de Fourier discr�te.
% 	tf(vectf) est la transform�e de Fourier discr�te de la fonction f
%       dont (ne) �chantillons sont rang�s dans le vecteur vectf. 
%	Ces �chantillons correspondent � des "instants" centr�s sur la 
%	valeur z�ro. La valeur de f(0) doit �tre contenue dans 
%	l'�chantillon (ne/2 + 1).
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


