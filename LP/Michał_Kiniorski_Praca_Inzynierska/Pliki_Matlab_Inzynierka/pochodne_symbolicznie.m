%F1=q/aw - C1*sqrt(H1)/aw    F2=C1*sqrt(H1)/(cw+(H2*b*w)/H2max) -
%C2*sqrt(H2)/(cw+(H2*b*w)/H2max)    F3= C2*sqrt(H2)/(w*sqrt(R^2-(R-H3)^2))
%- C3*sqrt(H3)/(w*sqrt(R^2-(R-H3)^2))

%na poczatku deklaracja wszystkich zmiennych
syms C1;
syms C2;
syms C3;
syms H1;
syms H2;
syms H3;
syms a;
syms b;
syms c;
syms w;
syms R;
syms H2max;
% najpierw obliczam pierwszy wiersz 
F1= -C1*sqrt(H1)/(a*w);
F2= C1*sqrt(H1)/(c*w+(H2*b*w)/H2max) - C2*sqrt(H2)/(c*w+(H2*b*w)/H2max);
F3= C2*sqrt(H2)/(w*sqrt(R^2-(R-H3)^2)) - C3*sqrt(H3)/(w*sqrt(R^2-(R-H3)^2));

dF11 = diff(F1,H1);
dF21 = diff(F2,H1);
dF22 = diff(F2,H2);
dF32 = diff(F3,H2);
dF33= diff(F3,H3);
syms q;
Q1=q/(a*w);
dQ1=diff(Q1,q);
zero=sym ('0'); 
syms A_symbolicznie;
syms B_symbolicznie;


pretty(dF11);
pretty(dF21);
pretty(dF22);
pretty(dF32);pretty(dF33);