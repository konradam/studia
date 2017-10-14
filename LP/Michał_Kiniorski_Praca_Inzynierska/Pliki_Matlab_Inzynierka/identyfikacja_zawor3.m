%identyfikacja parametrów modelu matematycznego zawor 3
global zbiornik;
c=10;
x0=35;
LB=[0 15]';
UB=[200 35]';
zbiornik=1;
parametry_optymalne3=lsqnonlin('cel',[c x0]',LB,UB,[],czas_zawor3_poprawiony,poziom_zawor3_poprawiony); 

[T3,X3]= ode45(@(t,x) rownania(t,x,parametry_optymalne3(1),3),czas_zawor3_poprawiony,parametry_optymalne3(2));