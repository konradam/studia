close all

plot(wykresy.time, wykresy.signals.values(:,1),'r', 'LineWidth', 2)
hold on
plot(wykresy.time, wykresy.signals.values(:,2),'b')
legend('Wartoœæ zadana','Poziom cieczy')
title('Zamkniêty uk³ad regulacji')
xlabel('Czas [s]')
ylabel('Poziom cieczy [cm]')
figure()
plot(sterowanie.time, sterowanie.signals.values(:,1),'r', 'LineWidth', 1.5)
xlabel('Czas [s]')
ylabel('Wspó³czynnik wype³nienia')
title('Przebieg czasowy sterowania pomp¹')
figure()
plot(sterowanie.time, sterowanie.signals.values(:,2),'r', 'LineWidth', 1.5)
xlabel('Czas [s]')
ylabel('Wspó³czynnik wype³nienia')
title('Przebieg czasowy sterowania elektrozaworem')