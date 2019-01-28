function [vf]=tfourinv(vFw)

if (size(vFw,1)==1)

	ne=size(vFw,2);

	i=sqrt(-1);
	nes2=ne/2;
	for n=1:ne
	   	vFw(n)=exp(-i*(n-nes2+1)*pi)*vFw(n);
	end
	vFw=fftshift(vFw);
	vf=ifft(vFw);
else 	'tfi : Le vecteur des données doit être un vecteur ligne'
end

