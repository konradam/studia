clear all;
close all;

P0 = 1;
I0 = 1;
D0 = 1;

[Nastawy] = fminsearch(@(x) wskaznikJakosci(x), [P0, D0]);
% [Nastawy] = fminsearch(@(x) wskaznikJakosciCzas(x), [P0, D0]);
% P = Nastawy(1);
% I = Nastawy(2);
% sim('modelZWoda');
% P1 = Nastawy(1);
% I1 = Nastawy(2);
% D1 = Nastawy(3);

% P1 = 1.089062371871661;
% I1 = .002562814996863;
% D1 = -0.001112798115117;
% P2 = 30.027479029282310;
% I2 = 0;
% D2 = -0.189641732763578;