close all
clear all

%% Prosty model z pidem jako regulatorem 
syms s
NUM = 1;
DEN = sym2poly((s+1)*(2*s+1)*(3*s+1)*(4*s+1)*(5*s+1)*(6*s+1));

MODEL = tf(NUM, DEN);

sampleTime = 0.01;
simulationTime = 150;
t = 0:sampleTime:simulationTime;
r = 0.3*sin(t*2*pi*0.1) + 0.3; % wartosc zadana podawana na PID

%% Symulacja
% simout = sim('symulacja_szumy', 'StopTime', num2str(max(t)));
% sim_data = simout.get('sim_data');
% y = sim_data.signals(1).values'; % wyjœcie
% u = sim_data.signals(2).values'; % sterowanie

simout = sim('generacjaSygnalu', 'StopTime', num2str(max(t)));
sim_data = simout.get('sim_data');
y = sim_data.signals.values(:,1)'; % wyjœcie
u = sim_data.signals.values(:,2)'; % sterowanie



%% Zapisz dane
% save('probka_szum.mat', 't','y', 'u');
save('probka_szum_2.mat', 't','y', 'u');
%% Inne podejœcie
% Bia³y szum gaussowski
% u = wgn(size(t,1),size(t,2), 0.1);
% x0 = 0;
% y = lsim(MODEL,u,t,x0,'zoh');
% plot(t,u, t,y)