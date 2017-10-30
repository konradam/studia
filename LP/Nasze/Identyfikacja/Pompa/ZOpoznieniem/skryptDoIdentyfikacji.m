close all;
clear all;

przepustowosc = 26.76;
tau0 = 1/20;

% wyliczone wartosci dla poszczegolnych pwm 0.3:0.1:1
% tau = [1.137265625000004
% 1.084433593750004
% 1.099101562500004
% 1.121074218750005
% 1.130048828125004
% 1.123125000000004
% 1.099609375000004
% 1.077187500000004];


p1 = [-53.386904761904304 2.090089285714280e+02 -16.628273809523616];

[Parametry] = fminsearch(@(x) wskaznikJakosci(x), [tau0]);
tau = Parametry(1);
% c2 = Parametry(2);
% c3 = Parametry(3);
load('pompa_09.mat', 'TankLevel');
PWM = 0.9;

T_sim = TankLevel.time(end,1);
poziom = TankLevel.signals.values(:,1);
h0 = poziom(1);

sim('pompa_identyfikacja')

figure()

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