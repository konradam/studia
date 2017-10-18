clear all;
close all;

% p1 = [[215.917508417508 -485.517316017315 478.461604136604 -68.0667460317460]];

PWM_level = .4:.1:1;
pred_napelniania = [8.09 14.60 18.07 21.82 24.68 25.73 26.76];

figure()
plot(PWM_level, pred_napelniania, 'r*');
hold on;
p1 = polyfit(PWM_level, pred_napelniania, 3);
osx1 = linspace(min(PWM_level),max(PWM_level),1000);
f1 = polyval(p1, osx1);
plot(osx1,f1);
axis([.4 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Wydajnoœæ zaworu [cm^3/s]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;


%% oprozanienie zaworem PWM = 1

load('zaworGora_pwm_1.mat', 'TankLevel');
sim('model_zaworGora')

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

