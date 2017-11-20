close all;
clear all;

%% Model obiektu
% L = 1;
% M = [720 1764 1624 735 175 21 1];
% MODEL = tf(L,M);
% 
% t = 0:0.01:60;
% 
% [y,t] = step(MODEL,t);

%% Lub za³aduj dane z identyfikacji
load zidentyfikowana_odpowiedz.mat

%% Strejc - parametry i modele
h_n     = [0.2642611, 0.3233236, 0.3527681, 0.371163];
T_mn    = [0.34605, 0.30099, 0.27168, 0.25040];
t_n     = zeros(size(h_n));
T_n     = zeros(size(h_n));
tau_n   = zeros(size(h_n));
tau_n1  = zeros(size(h_n));
tau_mn  = [1.34605, 1.60199, 1.81504, 2.00160];
T90     = get_point(t,y,0.90);

NUM     = 1;
DEN     = zeros(length(h_n), 6);
y_n     = zeros(length(y), length(h_n));
error   = zeros(size(h_n));
syms s

for i = 1:length(h_n)
    t_n(i)      = get_point(t,y,h_n(i));
    T_n(i)      = T_mn(i) * (T90 - t_n(i));
    tau_n(i)    = t_n(i) - i * T_n(i);
    tau_n1(i)   = tau_mn(i)*t_n(i) - i*T90*T_mn(i); % tau_n1 == tau_n -> tak dla sprawdzenia
    DEN(i,5-i:end) = sym2poly((T_n(i)*s + 1)^(i+1));
    if (tau_n(i)<0) tau_n(i) = 0; end;
    SYS(i)      = tf(NUM, DEN(i,:), 'InputDelay', tau_n(i));
    [y_n(:,i),t]= step(SYS(i), t);
    error(i) = sum((y - y_n(:,i)).^2);
end


%%
F = figure();
hold on
colors = lines(5);
plot(t,y, 'Color', colors(5,:), 'LineWidth', 2);
for i = 1:4
    plot(t,y_n(:,i), 'Color', colors(i,:), 'LineWidth', 1.5);
end
plot(t,y, 'Color', colors(5,:), 'LineWidth', 2); % aby by³ widoczny
put_line(T90,0.90, colors(5, :));
for i = 1:4
    put_line(t_n(i), h_n(i), colors(i, :));
end
legend('obiekt', '2', '3', '4', '5');

title('OdpowiedŸ skokowa obiektu oraz dopasowane modele Strejca');
plot_pdf(F, 'model_strejc', [600,400]);

