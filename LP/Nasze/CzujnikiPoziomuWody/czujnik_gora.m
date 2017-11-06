clear all;
close all;

H_poziom = 5:5:30;

load('poziom_5.mat');
zbiornik_1(1) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

load('poziom_10.mat');
zbiornik_1(2) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

load('poziom_15.mat');
zbiornik_1(3) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

load('poziom_20.mat');
zbiornik_1(4) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

load('poziom_25.mat');
zbiornik_1(5) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

load('poziom_30.mat');
zbiornik_1(6) = mean(RawVoltage.signals.values(:,1));
clear RawVoltage;

figure()
plot(zbiornik_1,H_poziom, 'r*');
hold on;
p1 = polyfit(zbiornik_1, H_poziom,1);
osx1 = linspace(min(zbiornik_1)-0.1,max(zbiornik_1)+0.1,1000);
f1 = polyval(p1, osx1);
plot(osx1,f1);
axis([min(zbiornik_1)-0.1,max(zbiornik_1)+0.1 0 35]);
xlabel('Napiêcie [V]');
ylabel('Poziom cieczy [cm]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;