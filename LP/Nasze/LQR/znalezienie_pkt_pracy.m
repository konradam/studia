clear all;
close all;

load('parametryWielomianuPWMPompy.mat')
load('parametryWielomianuPWMZaworu.mat')
load('parametryWielomianuC1Zaworu.mat')
load('parametryWielomianuC2Zaworu.mat')

syms q w w_q w_z
xr = 20;
w_q = p1(1)*q^2 + p1(2)*q + p1(3);
w_z = (zaworP1(1)*w^2 + zaworP1(2)*w + zaworP1(3)) * (zaworC2(1)*w^2 + zaworC2(2)*w + zaworC2(3)) * exp(xr*(zaworC1(1)*w^3 + zaworC1(2)*w^2 + zaworC1(3)*w + zaworC1(4)));

eqn = w_q == 139.79;
eqn = w_z == 26.76;
temp = solve(eqn, w)