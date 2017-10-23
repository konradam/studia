function Q = wskaznikJakosci(params)

%wczytanie pomiarów
load('zaworGora_1.mat', 'TankLevel');
PWM = 1;
poziom = TankLevel.signals.values(1:end,1);
czas = TankLevel.time(1:end,1);
p1 = [-49.142857142857010 99.114285714285490 -23.369999999999905];

c1 = params(1);
c2 = params(2);
c3 = params(3);
tSim = czas(end);
% sim('Identyfikacja');
options = simset('SrcWorkspace','current','DstWorkspace','current');
sim('Identyfikacja',[0 tSim], options);
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

Q = sum(abs(poziom - poziom_model));

end