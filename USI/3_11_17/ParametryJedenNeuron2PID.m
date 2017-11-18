% clear all;
% close all;

R = 2;
k = 0.1;
ke = 5;
mr = 5;
r = 0.5;
mw = 0.5;
L = 0.1;

%moment bezwladnosci ramienia
Jr = 1/3*mr*r*r;

%moment bezw³adnoœci bez wody
J1 = Jr;

%moment bezw³adnoœci z wod¹
J2 = Jr + mw * r*r;

P1 = 0.9102;
I1 = 2.8992e-08;
P2 = 0.738385826082795;
I2 = 0.004789704258728;


W = [P1 I1 0
     P2 I2 0
     0  0  1 ];