clear all;
close all;
%testy regulatora

%pierwszy test
%Q=5 1 10 R=30  K=[0.0311 0.0151 0.0068]  H1=7.4 H2=17 i H3=10;
K=[0.0311 0.0151 0.0068];
load regulator28listopad.mat;
figure();
plot(czasSterowanie06,H1sterowanie06poziom,czasSterowanie06,H2sterowanie06poziom,czasSterowanie06,H3sterowanie06poziom);
hold on;
title(['Dzia³anie regulatora LQ dla K = [' ,num2str(K(1)),' ',num2str(K(2)),' ',num2str(K(3)),']'], 'FontSize',14);
legend('Poziom w zbiorniku górnym','Poziom w zbiorniku œrodkowym','Poziom w zbiorniku dolnym','FontSize',14);
grid;
set(gca,'fontsize',14);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',14);
ylabel('Poziom cieczy [cm]','FontSize',14);
hold off;

figure();
plot(czasSterowanie06,sterowanie06regulator);
hold on;
title(['Przebieg sterowania dla K = [' ,num2str(K(1)),' ',num2str(K(2)),' ',num2str(K(3)),']'], 'FontSize',14);
grid;
set(gca,'fontsize',14);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',14);
ylabel('Sterowanie','FontSize',14);
hold off;

figure();
plot(czasSterowanie06zaklocenie,H1sterowanie06poziomzaklocenie,czasSterowanie06zaklocenie,H2sterowanie06poziomzaklocenie,czasSterowanie06zaklocenie,H3sterowanie06poziomzaklocenie);
hold on;
title(['Dzia³anie regulatora LQ dla K = [' ,num2str(K(1)),' ',num2str(K(2)),' ',num2str(K(3)),'] przy chwilowym zak³oceniu'], 'FontSize',14);
legend('Poziom w zbiorniku górnym','Poziom w zbiorniku œrodkowym','Poziom w zbiorniku dolnym','FontSize',14);
grid;
set(gca,'fontsize',14);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',14);
ylabel('Poziom cieczy [cm]','FontSize',14);
hold off;

figure();
plot(czasSterowanie06zaklocenie,sterowanie06regulatorzaklocenie);
hold on;
title(['Przebieg sterowania dla K = [' ,num2str(K(1)),' ',num2str(K(2)),' ',num2str(K(3)),'] przy chwilowym zak³óceniu'], 'FontSize',14);
grid;
set(gca,'fontsize',14);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',14);
ylabel('Sterowanie','FontSize',14);
hold off;
