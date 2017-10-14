%%zawor2 optymalizacja fminsearch
close all;

load wymiary.mat;
load daneZawory_cz2.mat;
global C2;
global x02;
global pomiar_zawor2;
global C2a;
global x02a;
global alfa2;
global pomiar_zawor2a;
pomiar_zawor2=poziom_zawor2_poprawiony;
pomiar_zawor2a=poziom_zawor2_poprawiony;
[parametry_zawor2_reczny]=fminsearch(@wskaznikZawor2,[5 pomiar_zawor2(1)]);
sim('identyfikacja_zawor2_reczny.slx');
[parametry_zawor2_reczny_alfa]=fminsearch(@wskaznikZawor2alfa,[5 pomiar_zawor2a(1) 0.5]);
sim('identyfikacja_zawor2_reczny_alfa.slx');

figure();
plot(H2.time, H2.signals.values,'r-','LineWidth',2);
hold on;
plot(czas_zawor2_poprawiony,poziom_zawor2_poprawiony,'LineWidth',3);
%plot(H2a.time,H2a.signals.values,'g-','LineWidth',2);

legend('Przebieg dla modelu','Przebieg dla pomiarów','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;