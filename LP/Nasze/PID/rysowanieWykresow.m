close all

plot(wykresy.time, wykresy.signals.values(:,1),'r', 'LineWidth', 2)
hold on
plot(wykresy.time, wykresy.signals.values(:,2),'b')
legend('Warto�� zadana','Poziom cieczy')
title('Zamkni�ty uk�ad regulacji')
xlabel('Czas [s]')
ylabel('Poziom cieczy [cm]')
figure()
plot(sterowanie.time, sterowanie.signals.values(:,1),'r', 'LineWidth', 1.5)
xlabel('Czas [s]')
ylabel('Wsp�czynnik wype�nienia')
title('Przebieg czasowy sterowania pomp�')
figure()
plot(sterowanie.time, sterowanie.signals.values(:,2),'r', 'LineWidth', 1.5)
xlabel('Czas [s]')
ylabel('Wsp�czynnik wype�nienia')
title('Przebieg czasowy sterowania elektrozaworem')