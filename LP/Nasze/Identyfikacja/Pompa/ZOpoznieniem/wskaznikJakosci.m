function Q = wskaznikJakosci(params)

%wczytanie pomiarów
load('pompa_09.mat', 'TankLevel');
PWM = 0.9;
poziom = TankLevel.signals.values(1:end,1);
czas = TankLevel.time(1:end,1);
p1 = [-53.386904761904304 2.090089285714280e+02 -16.628273809523616];

h0 = poziom(1);
tau = params(1);
% c2 = params(2);
% c3 = params(3);
tSim = czas(end);
% sim('Identyfikacja');
options = simset('SrcWorkspace','current','DstWorkspace','current');
sim('pompa_identyfikacja',[0 tSim], options);
czas_model = TankLevelModel.time(:,1);
poziom_model = TankLevelModel.signals.values(:,1);

Q = sum(abs(poziom - poziom_model));

end