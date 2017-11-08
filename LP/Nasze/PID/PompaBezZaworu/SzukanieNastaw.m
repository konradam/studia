clear all;
close all;

P0 = 1;
I0 = 1;
D0 = 1;

[Nastawy] = fminsearch(@(x) wskaznikJakosci(x), [P0, I0, D0]);
% [Nastawy] = fminsearch(@(x) wskaznikJakosciCzas(x), [P0, D0]);
% P = Nastawy(1);
% I = Nastawy(2);
% sim('modelZWoda');
P1 = Nastawy(1);
I1 = Nastawy(2);
D1 = Nastawy(3);

% P1 = 1.559211858494873;
% I1 = 5.687643061134081e-04;
% D1 = 1.333293908881934;
