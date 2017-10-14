%optymalizacja reczne wszystko dla pierwiastka
optymalizacja_zawor1;
optymalizacja_zawor2;
optymalizacja_zawor3;

figure();
plot(H1.time, H1.signals.values,'r-','LineWidth',2);
hold on;
plot(czas_zawor1_poprawiony,poziom_zawor1_poprawiony,'LineWidth',2);
title('Porównanie charakterystyk dynamicznych zaworu rêcznego w górnym zbiorniku dla pomiarów i modelu','FontSize',14);
legend('Model','Pomiar','FontSize',14);
grid;
set(gca,'fontsize',14);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',14);
ylabel('Poziom [cm]','FontSize',14);
hold off;

figure();
plot(H2.time, H2.signals.values);
hold on;
plot(czas_zawor2_poprawiony,poziom_zawor2_poprawiony);
hold off;

figure();
plot(H3.time, H3.signals.values);
hold on;
plot(czas_zawor3_poprawiony,poziom_zawor3_poprawiony);
hold off;
