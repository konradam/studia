% clear all;
% close all;
% 
% % p1 = [[-49.142857142857010 99.114285714285490 -23.369999999999905]];
% 
% PWM_level = .4:.1:1;
% pred_napelniania = [8.09 14.60 18.07 21.82 24.68 25.73 26.76];
% 
% figure()
% plot(PWM_level, pred_napelniania, 'r*');
% hold on;
% % zaworP1 = polyfit(PWM_level, pred_napelniania, 2);
% load('parametryWielomianuPWMZaworu.mat')
% osx1 = linspace(min(PWM_level),max(PWM_level),1000);
% f1 = polyval(zaworP1, osx1);
% plot(osx1,f1);
% axis([.4 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
% xlabel('Wspó³czynnik wype³nienia PWM');
% ylabel('Wydajnoœæ zaworu [cm^3/s]');
% legend('Wartoœci zmierzone', 'Aproksymacja')
% hold off;
% 
% 
% 
% %% parametr C1 - przyjêto wartoœæ C1 = -0.0194 - œrednia wartoœæ 
% load('parametrC1.mat')
% PWM_level_C1 = .4 : .15 : 1;
% figure()
% plot(PWM_level_C1, C1, 'r*');
% hold on;
% 
% % zaworC1 = polyfit(PWM_level_C1, C1, 3);
% load('parametryWielomianuC1Zaworu.mat')
% osxC1 = linspace(min(PWM_level_C1),max(PWM_level_C1),1000);
% fC1 = polyval(zaworC1, osxC1);
% plot(osxC1,fC1);
% xlabel('Wspó³czynnik wype³nienia PWM');
% ylabel('Parametr C1');
% 
% %% parametr C2 
% load('parametrC2.mat')
% PWM_level_C2 = .4 : .15 : 1;
% figure()
% plot(PWM_level_C2, C2, 'r*');
% hold on;
% 
% % zaworC2 = polyfit(PWM_level_C2, C2, 2);
% load('parametryWielomianuC2Zaworu.mat')
% osxC2 = linspace(min(PWM_level_C2),max(PWM_level_C2),1000);
% fC2 = polyval(zaworC2, osxC2);
% plot(osxC2,fC2);
% xlabel('Wspó³czynnik wype³nienia PWM');
% ylabel('Parametr C2');
% 
% %%
% 
% 
% % p1 = [[215.917508417508 -485.517316017315 478.461604136604 -68.0667460317460]];
% 
% PWM_level = .2:.1:1;
% pred_napelniania = [8.69 39.9 59.52 75.97 89.99 102.46 115.05 128.27 139.79];
% 
% figure()
% plot(PWM_level, pred_napelniania, 'r*');
% hold on;
% % pompaP1 = polyfit(PWM_level, pred_napelniania, 3);
% load('parametryWielomianuPWMPompy.mat')
% osx1 = linspace(min(PWM_level),max(PWM_level),1000);
% f1 = polyval(pompaP1, osx1);
% plot(osx1,f1);
% axis([.2 1 min(pred_napelniania)-1,max(pred_napelniania)+1]);
% xlabel('Wspó³czynnik wype³nienia PWM');
% ylabel('Wydajnoœæ pompy [cm^3/s]');
% legend('Wartoœci zmierzone', 'Aproksymacja')
% hold off;
% 
% %%
% pompaPWM = 0;
% zaworPWM = 1;
% T_sim = 200;
% 
% h0 = 30;

%%
load('parametryWielomianuPWMPompy.mat')
load('parametryWielomianuPWMZaworu.mat')
load('parametryWielomianuC1Zaworu.mat')
load('parametryWielomianuC2Zaworu.mat')
h0 = 30;