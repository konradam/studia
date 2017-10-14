close all;
load wymiary.mat;
load daneZawory;
load danePompa;
%linearyzacja;
linearyzacja_analitycznie
ustalony=[0.6 0.65 0.7 0.75 0.8];
ustalony(tryb);
Q=[5 0 0; 0 1 0; 0 0 15];
R=40;
[K,S,eig]=lqr(A,B,Q,R);
%Q=[parametry_LQ(1) 0 0; 0 parametry_LQ(2) 0; 0 0 parametry_LQ(3)];
 %   R=abs(parametry_LQ(4));
sim('Regulator.mdl');
figure();
plot(H_lqr.time,H_lqr.signals.values(:,1),'LineWidth',2);
hold on;
%title(['Przebiegi symulacyjne poziomów w zbiornikach dla trybu ',num2str(tryb)],'FontSize',16);

grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
plot(H_lqr.time,H_lqr.signals.values(:,2),'r','LineWidth',2);
plot(H_lqr.time,H_lqr.signals.values(:,3),'g','LineWidth',2);
legend('H1','H2','H3','FontSize',16);
hold off;

figure();

plot(q_lqr.time,q_lqr.signals.values,'LineWidth',2);


hold on;
title(['Przebieg symulacyjny sterowania dla trybu ',num2str(tryb)],'FontSize',16);
%legend('Poziom cieczy w zbiorniku górnym','Poziom cieczy w zbiorniu œrodkowym','Poziom cieczy w zbiorniku dolnym','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Sterowanie ','FontSize',16);
hold off;

i=tryb;

sterowanie_regulator(:,i)=q_lqr.signals.values;
sterowanie_czas(:,i)=q_lqr.time;