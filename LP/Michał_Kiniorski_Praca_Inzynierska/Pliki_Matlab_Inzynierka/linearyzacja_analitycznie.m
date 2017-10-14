%load wyznaczoneParametry25listopad;
load wymiary;
%wyznaczone 25 listopada przy sterowanie w stanie ustalonym 0.57
%H1pp=8;
%H2pp=14.75;
%H3pp=10;
%C1=30.6811;
%C2=22.5954;
%C3= 27.4420;
par=input('Podaj tryb ktory chcesz wybrac (1-5)');
if par<6 && par>1
    tryb=par;
else
    tryb=1;
end;

%wyznaczone 28 listopada przy sterowanie w stanie ustalonym 0.6 (widocznie
%inne ustawienie zaworow)
%wyznaczone 19 grudnia
H1pomoc=[5.5 7.4 9.6 11.8  14];
H2pomoc=[10.3 14.2 18 22.5 25.5];
H3pomoc=[7.4 9.6 11.6 14.5  16.5];
sterowanie_pomoc=[74.1  82.7842  91.1505 99.2869 107.2806];


H1pp=H1pomoc(tryb);
H2pp=H2pomoc(tryb);
H3pp=H3pomoc(tryb);
q=sterowanie_pomoc(tryb);
%q=86.3401        0.53
%q=88.8935         0.55
%q=94.8662          0.6
%q=101.5194         0.65
%q=105.7288         0.7
C1=q/sqrt(H1pp);
C2=q/sqrt(H2pp);
C3=q/sqrt(H3pp);
pomoc1=c*w+H2pp*b*w/H2max;
pomoc2=2*w*(R^2-(H3pp-R)^2)^(3/2);
A11= -C1/(2*sqrt(H1pp)*a*w);
A12=0;
A13=0;
A21=C1/(2*sqrt(H1pp)*pomoc1);
A22=(-C1*sqrt(H1pp)*b*w)/(H2max*pomoc1^2)+(C2*sqrt(H2pp)*b*w)/(H2max*pomoc1^2) - C2/(2*sqrt(H2pp)*pomoc1);
A23=0;
A31=0;
A32=C2/(2*sqrt(H2pp)*w*sqrt(R^2-(H3pp-R)^2));
A33=C2*sqrt(H2pp)*(2*H3pp-2*R)/pomoc2 - C3*sqrt(H3pp)*(2*H3pp-2*R)/pomoc2 - C3/(2*sqrt(H3pp)*w*sqrt((R^2-(H3pp-R)^2))) ;
A=[A11 A12 A13; A21 A22 A23; A31 A32 A33];
B11=[1/(a*w); 0 ; 0];
B=B11;
x(1)=H1pp;
x(2)=H2pp;
x(3)=H3pp;

A11=sym('A11');
pretty(A11);
