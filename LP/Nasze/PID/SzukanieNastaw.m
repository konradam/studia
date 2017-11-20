clear all;
close all;

P01 = 1;
D01 = 1;
P02 = 1;
D02 = 1;
% [Nastawy] = fminsearch(@(x) wskaznikJakosci(x), [P0, D0]);

lb = [0.3 0.4];
ub = [1, 1];
% [Nastawy] = fmincon(@(x) wskaznikJakosci2(x), [P01, D01, P02, D02],[],[],[],[], lb, ub);
[Nastawy] = fminsearch(@(x) wskaznikJakosci2(x), [P01, D01, P02, D02]);
% [Nastawy] = fminsearch(@(x) wskaznikJakosciCzas(x), [P0, D0]);
% P = Nastawy(1);
% I = Nastawy(2);
% sim('modelZWoda');
P1 = Nastawy(1);
I1 = Nastawy(2);
D1 = Nastawy(2);

% P1 = 1.089062371871661;
% I1 = .002562814996863;
% D1 = -0.001112798115117;
% P2 = 30.027479029282310;
% I2 = 0;
% D2 = -0.189641732763578;