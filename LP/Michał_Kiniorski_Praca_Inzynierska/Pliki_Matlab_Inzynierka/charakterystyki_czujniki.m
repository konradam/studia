close all;
load daneCzujniki.mat;
%%skalowanie czujnikow
%sensor1
czujnik1=[ 0.3281,0.6571,0.9751,1.2975,1.6131,1.9271];
poziom1=[ 5,10,15,20,25,30];
wielomian_czujnik1=polyfit(czujnik1,poziom1,1);
wektor_czujnik1=0:0.01:2;
wartosci_czujnik1=polyval(wielomian_czujnik1,wektor_czujnik1);
%sensor2
czujnik2=[ 0.3206,0.6472,0.9791,1.3076,1.6191,1.9424];
poziom2=[ 5,10,14.9,20,25,30];
wielomian_czujnik2=polyfit(czujnik2,poziom2,1);
wektor_czujnik2=0:0.01:2; 
wartosci_czujnik2 = polyval(wielomian_czujnik2,wektor_czujnik2);
%sensor3
czujnik3=[ 1.1580,1.3580,1.5580,1.7540,1.9540,2.1540];
poziom3=[ 5,10,15,20,25,30];
wielomian_czujnik3=polyfit(czujnik3,poziom3,1);
wektor_czujnik3=0:0.01:2.4;
wartosci_czujnik3=polyval(wielomian_czujnik3,wektor_czujnik3);
%charakterystyki przetwarzania czujników
%czujnik 1
figure();
plot(wektor_czujnik1,wartosci_czujnik1,'b','LineWidth',2);
hold on;
plot(czujnik1,poziom1,'r*','MarkerSize',14);
axis([0 2 0 35 ]);

legend('H1','U1','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Napiêcie [V]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;

%czujnik 2
figure();
plot(wektor_czujnik2,wartosci_czujnik2,'b','LineWidth',2);
hold on;
plot(czujnik2,poziom2,'r*','MarkerSize',14);
axis([0 2 0 35 ]);

legend('H2','U2','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Napiêcie [V]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;

%czujnik3
figure();
plot(wektor_czujnik3,wartosci_czujnik3,'b','LineWidth',2);
hold on;
plot(czujnik3,poziom3,'r*','MarkerSize',14);
axis([1 2.4 0 35 ]);

legend('H3','U3','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Napiêcie [V]','FontSize',16);
ylabel('Poziom [cm]','FontSize',16);
hold off;