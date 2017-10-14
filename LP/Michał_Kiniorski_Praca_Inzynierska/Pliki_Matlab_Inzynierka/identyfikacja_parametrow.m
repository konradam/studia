clear all;
close all;
load('daneZawory.mat');

t11=czas_zawor1_poprawiony;
t22=czas_zawor2_poprawiony;
t33=czas_zawor3_poprawiony;

x11=poziom_zawor1_poprawiony;
x22=poziom_zawor2_poprawiony;
x33=poziom_zawor3_poprawiony;


%% zad 1
global nr_zb;

LB=[0.1 0.5 25]';% ograniczenia
UB=[200 0.51 35]';% ograniczenia

c=10;
al=0.5;
x0=30;
nr_zb=1;
xopt1=lsqnonlin('cel',[c al x0]',LB,UB,[],t11,x11); 
%xopt(1) = copt
%xopt(2) = alfaopt
%xopt(3) = xopt
nr_zb=2;
xopt2=lsqnonlin('cel',[c al x0]',LB,UB,[],t22,x22);
nr_zb=3;
xopt33=lsqnonlin('cel',[c al x0]',LB,UB,[],t33,x33);

%% rozwiazanie dla zad 1
[t1,x1] = ode45(@(t,x) rhs(t,x,xopt1(1),xopt1(2),1),t11,xopt1(3));
figure
hold on;
plot(t11,x11,'b');
plot(t1,x1,'r','LineWidth',2);
hold off
legend('przebieg dla zbiornika 1','Poziom w 1 zbiorniku dla modelu 1');

[t2,x2] = ode45(@(t,x) rhs(t,x,xopt2(1),xopt2(2),2),t22,xopt2(3));
figure
hold on;
plot(t22,x22,'k');
plot(t2,x2,'r','LineWidth',2);
hold off
legend('przebieg dla zbiornika 2','Poziom w 2 zbioniku dla modelu 1');

[t33,x3] = ode45(@(t,x) rhs(t,x,xopt33(1),xopt33(2),3),t33,xopt33(3));
figure
hold on;
plot(t33,x33,'g');
plot(t33,x3,'r','LineWidth',2);
hold off
legend('przebieg dla zbionika 3','Poziom w 3 zbioniku dla modelu 1');


%wyliczenie b³êdów
blad1=sum((x11-x1).^2);
blad2=x22-x2;
blad3=x33-x3;

wariancja1=var(blad1);
wariancja2=var(blad2);
wariancja=var(blad3);
