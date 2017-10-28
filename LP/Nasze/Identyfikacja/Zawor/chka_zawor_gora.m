clear all;
close all;

% p1 = [[-49.142857142857010 99.114285714285490 -23.369999999999905]];

PWM_level = .4:.1:1;
pred_napelniania = [8.09 14.60 18.07 21.82 24.68 25.73 26.76];

figure()
plot(PWM_level, pred_napelniania, 'r*');
hold on;
p1 = polyfit(PWM_level, pred_napelniania, 2);
osx1 = linspace(min(PWM_level),max(PWM_level),1000);
f1 = polyval(p1, osx1);
plot(osx1,f1);
axis([.4 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Wydajnoœæ zaworu [cm^3/s]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;

%% parametr C1 - przyjêto wartoœæ C1 = -0.0194 - œrednia wartoœæ 
load('parametrC1.mat')
PWM_level_C1 = .4 : .15 : 1;
figure()
plot(PWM_level_C1, C1, 'r*');
hold on;

pC1 = polyfit(PWM_level_C1, C1, 3);
osxC1 = linspace(min(PWM_level_C1),max(PWM_level_C1),1000);
fC1 = polyval(pC1, osxC1);
plot(osxC1,fC1);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Parametr C1');

%% parametr C2 
load('parametrC2.mat')
PWM_level_C2 = .4 : .15 : 1;
figure()
plot(PWM_level_C2, C2, 'r*');
hold on;

pC2 = polyfit(PWM_level_C2, C2, 2);
osxC2 = linspace(min(PWM_level_C2),max(PWM_level_C2),1000);
fC2 = polyval(pC2, osxC2);
plot(osxC2,fC2);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Parametr C2');
%% oprozanienie zaworem PWM = 1
PWM = 1;
load('zaworGora_1.mat', 'TankLevel');
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
T_sim = czas(end);
h0 = poziom(1);
figure()
subplot(5,1,1)
plot(czas, poziom,'b');
hold on


load('parametryIdentyfikacja.mat')
% sim('model_zaworGora')
sim('model_zaworGora_C1')
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')
title('Przebieg opró¿niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 1')
%% oprozanienie zaworem PWM = 0.85
PWM = 0.85;
clear poziom czas czas_model poziom_model
load('zaworGora_085.mat', 'TankLevel');

% figure()
subplot(5,1,2)
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
T_sim = czas(end);
h0 = poziom(1);
plot(czas, poziom,'b');
hold on


load('parametryIdentyfikacja.mat')
% sim('model_zaworGora')
sim('model_zaworGora_C1')
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
% legend('Wartoœci zmierzone', 'Model')
title('Przebieg opró¿niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.85')
%% oprozanienie zaworem PWM = 0.7
PWM = 0.7;
clear poziom czas czas_model poziom_model
load('zaworGora_07.mat', 'TankLevel');

% figure()
subplot(5,1,3)
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
T_sim = czas(end);
h0 = poziom(1);
plot(czas, poziom,'b');
hold on


load('parametryIdentyfikacja.mat')
% sim('model_zaworGora')
sim('model_zaworGora_C1')
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
% legend('Wartoœci zmierzone', 'Model')
title('Przebieg opró¿niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.7')
%% oprozanienie zaworem PWM = 0.55
PWM = 0.55;
clear poziom czas czas_model poziom_model
load('zaworGora_055.mat', 'TankLevel');

% figure()
subplot(5,1,4)
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
T_sim = czas(end);
h0 = poziom(1);
plot(czas, poziom,'b');
hold on


load('parametryIdentyfikacja.mat')
% sim('model_zaworGora')
sim('model_zaworGora_C1')
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
% legend('Wartoœci zmierzone', 'Model')
title('Przebieg opró¿niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.55')
%% oprozanienie zaworem PWM = 0.4
PWM = 0.4;
clear poziom czas czas_model poziom_model
load('zaworGora_04.mat', 'TankLevel');

% figure()
subplot(5,1,5)
poziom = TankLevel.signals.values(:,1);
czas = TankLevel.time(:,1);
T_sim = czas(end);
h0 = poziom(1);
plot(czas, poziom,'b');
hold on


load('parametryIdentyfikacja.mat')
% sim('model_zaworGora')
sim('model_zaworGora_C1')
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

plot(czas_model, poziom_model,'r', 'Linewidth',1);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
% legend('Wartoœci zmierzone', 'Model')
title('Przebieg opró¿niania zbiornika dla wartoœci sygna³u wype³nienia PWM = 0.4')