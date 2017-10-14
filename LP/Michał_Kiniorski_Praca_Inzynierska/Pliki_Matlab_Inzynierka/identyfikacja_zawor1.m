%identyfikacja parametrów modelu matematycznego

c1=10;
x01=33;
LB=[0.1 25]';
UB=[200 40]';
ym=poziom_zawor1_poprawiony(1);
parametry_optymalne1=lsqnonlin('cel1',[c1 x01]',LB,UB,[],czas_zawor1_poprawiony,poziom_zawor1_poprawiony); 

[T1,X1]= ode45(@(t,x) rownanie1(t,x,parametry_optymalne1(1)),czas_zawor1_poprawiony,parametry_optymalne1(2));