function Q = wskaznikJakosci(params)

%     R = 2;
%     k = 0.1;
%     ke = 5;
%     mr = 5;
%     r = 0.5;
%     mw = 0.5;
%     L = 0.1;
%
%     %moment bezwladnosci ramienia
%     Jr = 1/3*mr*r*r;
%
%     %moment bezw³adnoœci bez wody
%     J1 = Jr;
%
%     %moment bezw³adnoœci z wod¹
%     J2 = Jr + mw * r*r;
%
%
%     P = params(1);
%     I = params(2);
%
%     T_sim = 50;
%     options = simset('SrcWorkspace','current','DstWorkspace','current');
%     sim('modelJedenRegulator',[0 T_sim], options);
%     if I < 0
%         Q = sum(uchyb.signals.values.^2) + 500;
%     else
%         Q = sum(uchyb.signals.values.^2);
%     end




%wczytanie pomiarów
load('zaworGora_pwm_1.mat', 'TankLevel');
poziom = TankLevel.signals.values(1:18001,1);
czas = TankLevel.time(1:18001,1);

c1 = params(1);
c2 = params(2);
c3 = params(3);
tSim = 180;
% sim('Identyfikacja');
options = simset('SrcWorkspace','current','DstWorkspace','current');
sim('Identyfikacja',[0 tSim], options);
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

Q = sum(abs(poziom - poziom_model));

end