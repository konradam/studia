clear all;
close all;

pompaPWM = 1;
zaworPWM = 1;
lb = [0.2 0.4];
ub = [1 1];

[Nastawy] = fmincon(@(x) wskaznikJakosci(x), [pompaPWM, zaworPWM], [], [], [], [], lb, ub);

zaworPWM = Nastawy(2);
pompaPWM = Nastawy(1);

