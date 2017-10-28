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
zaworPWM = ur(2);
pompaPWM = ur(1);

[A B C D] = linmod('modelZbiornik2', xr, ur);