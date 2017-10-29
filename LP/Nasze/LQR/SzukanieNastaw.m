clear all;
close all;



pompaPWM = 1;
zaworPWM = 1;
lb = [0.2 0.4];
ub = [1 1];

[Nastawy] = fmincon(@(x) wskaznikJakosci(x), [pompaPWM, zaworPWM], [], [], [], [], lb, ub);

zaworPWM = Nastawy(2);
pompaPWM = Nastawy(1);

%%

load('parametryWielomianuPWMPompy.mat')
load('parametryWielomianuPWMZaworu.mat')
load('parametryWielomianuC1Zaworu.mat')
load('parametryWielomianuC2Zaworu.mat')
pompaP1 = p1;
h0 = 20;

xr = 20;
ur = [0.254860012262847 0.775110454488783];
% ur = [ 0.775110454488783 0.254860012262847];
zaworPWM = ur(2);
pompaPWM = ur(1);

[A B C D] = linmodv5('modelZbiornik2', xr, ur);

Q = 10000;
R = [10 0; 0 10];
K = lqr(A,B,Q,R);