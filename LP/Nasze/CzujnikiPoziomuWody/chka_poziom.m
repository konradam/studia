clear all;
close all;

% p1 = [15.444804929251072 -0.493197742577506];
% p2 = [15.404643089607289 -0.831525276632670];
% p3 = [24.676891662992784 -25.232150729749170];

H_poziom = 5:5:30;
zbiornik_1 = [0.35 0.68 1.01 1.33 1.65 1.97];
zbiornik_2 = [0.38 0.7 1.03 1.35 1.68 2];
zbiornik_3 = [1.22 1.43 1.63 1.84 2.04 2.23];

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

figure()
plot(zbiornik_2, H_poziom, 'r*');
hold on;
p2 = polyfit(zbiornik_2, H_poziom,1);
osx2 = linspace(min(zbiornik_2)-0.1,max(zbiornik_2)+0.1,1000);
f2 = polyval(p2, osx2);
plot(osx2,f2);
axis([min(zbiornik_2)-0.1,max(zbiornik_2)+0.1 0 35]);
xlabel('Napiêcie [V]');
ylabel('Poziom cieczy [cm]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;

figure()
plot(zbiornik_3, H_poziom, 'r*');
hold on;
p3 = polyfit(zbiornik_3, H_poziom,1);
osx3 = linspace(min(zbiornik_3)-0.1,max(zbiornik_3)+0.1,1000);
f3 = polyval(p3, osx3);
plot(osx3,f3);
axis([min(zbiornik_3)-0.1,max(zbiornik_3)+0.1 0 35]);
xlabel('Napiêcie [V]');
ylabel('Poziom cieczy [cm]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;