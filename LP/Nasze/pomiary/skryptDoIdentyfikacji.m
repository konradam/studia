close all;
clear all;

przepustowosc = 26.76;
c1 = 1/20;
c2 = 1/4;
c3 = 30.52;
tSim = 180;

[Parametry] = fminsearch(@(x) wskaznikJakosci(x), [c1, c2, c3]);
c1 = Parametry(1);
c2 = Parametry(2);
c3 = Parametry(3);
load('zaworGora_pwm_1.mat', 'TankLevel');
sim('Identyfikacja')

figure()
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);
plot(czas, poziom,'b');
hold on
plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')