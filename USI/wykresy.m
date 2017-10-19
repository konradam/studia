clear all;
close all;

load('stany.mat');
polozenie = simout.signals.values(:,1);
czas = simout.time(:,1);

figure()
plot(czas, polozenie, 'r');
xlabel('Czas [s]');
ylabel('Po³o¿enie ramienia [rad]');
title('Po³o¿enie ramienia')

predkosc = simout.signals.values(:,2);
czas = simout.time(:,1);

figure()
plot(czas, predkosc, 'r');
xlabel('Czas [s]');
ylabel('Predkoœæ ramienia [rad/s]');
title('Predkoœæ ramienia')

prad = simout.signals.values(:,3);
czas = simout.time(:,1);

figure()
plot(czas, prad, 'r');
xlabel('Czas [s]');
ylabel('Natê¿enie [I]');
title('Natê¿enie pr¹du wzbudzenia')