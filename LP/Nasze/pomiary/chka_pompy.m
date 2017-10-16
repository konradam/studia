clear all;
close all;

% p1 = [[215.917508417508 -485.517316017315 478.461604136604 -68.0667460317460]];

PWM_level = .2:.1:1;
pred_napelniania = [8.69 39.9 59.52 75.97 89.99 102.46 115.05 128.27 139.79];

figure()
plot(PWM_level, pred_napelniania, 'r*');
hold on;
p1 = polyfit(PWM_level, pred_napelniania, 3);
osx1 = linspace(min(PWM_level),max(PWM_level),1000);
f1 = polyval(p1, osx1);
plot(osx1,f1);
axis([.2 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
xlabel('Wspó³czynnik wype³nienia PWM');
ylabel('Wydajnoœæ pompy [cm^3/s]');
legend('Wartoœci zmierzone', 'Aproksymacja')
hold off;


%% napelnienia pomp¹ PWM = 1

load('pompa_pwm_1.mat', 'TankLevel');
sim('model_pompy')

figure()
poziom = TankLevel.signals.values(119:end,1);
czas = TankLevel.time(119:end,1)-1.18;
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);
plot(czas, poziom,'b');
hold on
plot(czas_model, poziom_model,'r', 'Linewidth',2);
axis([0 max(czas) 0 35]);
xlabel('Czas [s]');
ylabel('Poziom zbiornika [cm]');
legend('Wartoœci zmierzone', 'Model')


