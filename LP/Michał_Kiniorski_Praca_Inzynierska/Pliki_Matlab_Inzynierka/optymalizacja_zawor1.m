%%identyfikacja zawor1 optymalizacja
close all;
clear all;
load wymiary.mat;
load daneZawory_cz2.mat;
global C1;
global x01;
global pomiar_zawor1;
global C1a;
global x01a;
global pomiar_zawor1a;
global alfa;
pomiar_zawor1=poziom_zawor1_poprawiony;
pomiar_zawor1a=poziom_zawor1_poprawiony;
[parametry_zawor1_reczny]=fminsearch(@wskaznikZawor1,[5 pomiar_zawor1(1)]);
sim('identyfikacja_zawor1_reczny.slx');
[parametry_zawor1_reczny_alfa]=fminsearch(@wskaznikZawor1alfa,[5 pomiar_zawor1a(1) 0.5]);
sim('identyfikacja_zawor1_reczny_alfa.slx');

figure();
plot(H1.time, H1.signals.values,'r-','LineWidth',2);
hold on;
plot(czas_zawor1_poprawiony,poziom_zawor1_poprawiony,'LineWidth',3);
%plot(H1a.time,H1a.signals.values,'g-','LineWidth',2);
%title('Porównanie charakterystyk dynamicznych zaworu rêcznego w górnym zbiorniku dla pomiarów i modelu','FontSize',16);

legend('Przebieg dla modelu ','Przebieg dla pomiarów','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;