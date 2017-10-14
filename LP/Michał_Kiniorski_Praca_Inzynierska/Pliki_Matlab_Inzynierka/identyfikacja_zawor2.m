%identyfikacja parametrów modelu matematycznego zawor 2
global zbiornik;
c=10;
x0=35;
LB=[0 15]';
UB=[200 35]';
zbiornik=2;
parametry_optymalne2=lsqnonlin('cel',[c x0]',LB,UB,[],czas_zawor2_poprawiony,poziom_zawor2_poprawiony); 

[T2,X2]= ode45(@(t,x) rownania(t,x,parametry_optymalne2(1),2),czas_zawor2_poprawiony,parametry_optymalne2(2));