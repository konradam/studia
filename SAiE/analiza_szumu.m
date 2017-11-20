%% Z szumu zróbmy odpowiedŸ impulsow¹

close all
clear all
%% Wczytaj t,u,y
% load probka_szum.mat
load probka_szum_2.mat
%% Obetnij próbkê do 10000 próbek z koñca (100s)
% u = u(end-10000:end);
% y = y(end-10000:end);
% t = t(end-10000:end)-t(end-10000);

%% rekurencyjnie impulsowa i skokowa od razu
g = zeros(1, length(t)-1);
h = zeros(1, length(t));

for n = 1:(length(t)-1)
    suma = 0;
    for i = 2:n
        suma = suma + u(i)*g(n-i+1);
    end
    g(n) = 1/u(1)*(y(n+1) - suma);
    h(n+1) = h(n) + g(n);
    display(n)
end;

%% wykresy i zapis
plot(t(1:end-1),g, t,h);

y = h';
save('zidentyfikowana_odpowiedz.mat', 'y', 't')