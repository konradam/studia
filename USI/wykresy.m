clear all;
close all;

load('stany.mat');
polozenie = simout.signals.values(:,1);
czas = simout.time(:,1);

figure()
plot(czas, polozenie, 'r');
xlabel('Czas [s]');
ylabel('Po�o�enie ramienia [rad]');
title('Po�o�enie ramienia')

predkosc = simout.signals.values(:,2);
czas = simout.time(:,1);

figure()
plot(czas, predkosc, 'r');
xlabel('Czas [s]');
ylabel('Predko�� ramienia [rad/s]');
title('Predko�� ramienia')

prad = simout.signals.values(:,3);
czas = simout.time(:,1);

figure()
plot(czas, prad, 'r');
xlabel('Czas [s]');
ylabel('Nat�enie [I]');
title('Nat�enie pr�du wzbudzenia')