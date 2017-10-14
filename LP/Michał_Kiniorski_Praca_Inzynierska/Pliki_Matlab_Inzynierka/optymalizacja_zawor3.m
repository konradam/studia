%%zawor3 optymalizacja fminsearch
close all;

load wymiary.mat;
load daneZawory_cz2.mat;
global C3;
global x03;
global pomiar_zawor3;
global C3a;
global x03a;
global alfa3;
global pomiar_zawor3a;
pomiar_zawor3=poziom_zawor3_poprawiony;
pomiar_zawor3a=poziom_zawor3_poprawiony;
[parametry_zawor3_reczny]=fminsearch(@wskaznikZawor3,[10 pomiar_zawor3(1)]);
sim('identyfikacja_zawor3_reczny.slx');
[parametry_zawor3_reczny_alfa]=fminsearch(@wskaznikZawor3alfa,[10 pomiar_zawor3a(1) 0.5]);
sim('identyfikacja_zawor3_reczny_alfa.slx');

figure();
plot(H3.time, H3.signals.values,'r-','LineWidth',2);
hold on;
plot(czas_zawor3_poprawiony,poziom_zawor3_poprawiony,'LineWidth',2);
%plot(H3a.time, H3a.signals.values,'g-','LineWidth',2);

legend('Przebieg dla modelu','Przebieg dla pomiarów','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;
