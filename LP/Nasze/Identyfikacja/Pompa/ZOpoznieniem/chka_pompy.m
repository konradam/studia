clear all;
close all;

PWM_level = .3:.1:1;
pred_napelniania = [39.9 59.52 75.97 89.99 102.46 115.05 128.27 139.79];

figure()
plot(PWM_level, pred_napelniania, 'r*');
hold on;
p1 = polyfit(PWM_level, pred_napelniania, 2);
osx1 = linspace(min(PWM_level),max(PWM_level),1000);
f1 = polyval(p1, osx1);
plot(osx1,f1);
axis([.3 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Wydajnoœæ pompy [cm^3/s]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;

%% wyznaczenie tau

PWM_level = .3:.1:1;
load('tau.mat');

figure()
plot(PWM_level, tau, 'r*');
hold on;
tauP1 = polyfit(PWM_level, tau', 3);
osx1 = linspace(min(PWM_level),max(PWM_level),1000);
f1 = polyval(tauP1, osx1);
plot(osx1,f1);
axis([.3 1 min(tau)-0.1,max(tau)+0.1]);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Wspó³czynnik tau');
% legend('Wartoœci wyz', 'Aproksymacja')

%% napelnienia pomp¹ PWM = 1
PWM = 1;
load('pompa_1.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 1')


%% napelnienia pomp¹ PWM = 0.9
PWM = .9;
load('pompa_09.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.9')

%% napelnienia pomp¹ PWM = 0.8
PWM = 0.8;
load('pompa_08.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.8')

%% napelnienia pomp¹ PWM = 0.7
PWM = 0.7;
load('pompa_07.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.7')

%% napelnienia pomp¹ PWM = 0.6
PWM = 0.6;
load('pompa_06.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.6')

%% napelnienia pomp¹ PWM = 0.5
PWM = 0.5;
load('pompa_05.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.5')

%% napelnienia pomp¹ PWM = 0.4
PWM = 0.4;
load('pompa_04.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.4')

%% napelnienia pomp¹ PWM = 0.3
PWM = 0.3;
load('pompa_03.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
h0 = poziom(1);
figure()
% subplot(3,1,1)
plot(czas, poziom,'b');
hold on
T_sim = czas(end);
tau1 =tauP1(1) * PWM^3 + tauP1(2) * PWM^2 + tauP1(3) * PWM + tauP1(4);

sim('model_pompy')

czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg nape³niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.3')