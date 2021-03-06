close all;
clear all;

R = 2;
k = 0.1;
ke = 5;
mr = 5;
r = 0.5;
mw = 0.5;
L = 0.1;

%moment bezwladnosci ramienia
Jr = 1/3*mr*r*r;

%moment bezw�adno�ci bez wody
J1 = Jr;

%moment bezw�adno�ci z wod�
J1 = Jr + mw * r*r;
% 
% % A = [0 k/J; -ke/L -R/L];
% % B = [0; 1/L];
% % C = [1 0; 0 1];
% % D = [0; 0];
% 
%Nastawy regulatora
<<<<<<< HEAD
% P0 = 0.9525;
% I0 = 1.8273e-08;
P0 = 0.7384;
I0 = 0.0048;
% P0 = 20;
% I0 = 0.03;
=======
P0 = 0.9525;
I0 = 1.8273e-08;
>>>>>>> f927553f726acbd8f0af1d4e0de059e519711529
P = P0;
I = I0;
T_sim = 50;
sim('modelJedenRegulator');

%Pierwszy wska�nik
Q1 = sum(uchyb.signals.values.^2);

%Drugi wska�nik
data = regulator1.signals.values(:,1);
Q2 = 0;
flaga = 0;
for i = 1:length(data)
    if (data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05 && flaga == 0)
        Q2 = tout(i);
        flaga = 1;
    elseif ~(data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05)
        flaga = 0;
    end
end

%Trzeci wska�nik
Q3 = sum(sterowanie.signals.values.^2)*T_sim;

%%
%Poszukiwanie P I dla minimalizacji 1 wska�nika 
[Nastawy] = fminsearch(@(x) wskaJak1(x), [P0, I0]);
P = Nastawy(1);
I = Nastawy(2);
sim('modelJedenRegulator');

%Pierwszy wska�nik
Q11 = sum(uchyb.signals.values.^2);

%Drugi wska�nik
data = regulator1.signals.values(:,1);
Q21 = 0;
flaga = 0;
for i = 1:length(data)
    if (data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05 && flaga == 0)
        Q21 = tout(i);
        flaga = 1;
    elseif ~(data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05)
        flaga = 0;
    end
end

%Trzeci wska�nik
Q31 = sum(sterowanie.signals.values.^2)*T_sim;

%%
%Poszukiwanie P I dla minimalizacji 2 wska�nika 
[Nastawy] = fminsearch(@(x) wskaJak2(x), [P0, I0]);
P = Nastawy(1);
I = Nastawy(2);
sim('modelJedenRegulator');

%Pierwszy wska�nik
Q12 = sum(uchyb.signals.values.^2);

%Drugi wska�nik
data = regulator1.signals.values(:,1);
Q22 = 0;
flaga = 0;
for i = 1:length(data)
    if (data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05 && flaga == 0)
        Q22 = tout(i);
        flaga = 1;
    elseif ~(data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05)
        flaga = 0;
    end
end

%Trzeci wska�nik
Q32 = sum(sterowanie.signals.values.^2)*T_sim;

%%
%Poszukiwanie P I dla minimalizacji 4 wska�nika 
[Nastawy] = fminsearch(@(x) wskaJak4(x), [P0, I0]);
P = Nastawy(1);
I = Nastawy(2);
sim('modelJedenRegulator');

%Pierwszy wska�nik
Q14 = sum(uchyb.signals.values.^2);

%Drugi wska�nik
data = regulator1.signals.values(:,1);
Q24 = 0;
flaga = 0;
for i = 1:length(data)
    if (data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05 && flaga == 0)
        Q24 = tout(i);
        flaga = 1;
    elseif ~(data(i) >= pi/4 - 0.05 &&  data(i) <= pi/4 + 0.05)
        flaga = 0;
    end
end

%Trzeci wska�nik
Q34 = sum(sterowanie.signals.values.^2)*T_sim;
% 
% sim('modelJedenRegulator');
% plot(tout,regulator1.signals.values(:,1))
% uchyb.signals.values(end)

% calkaUchybu = 0;
% for i=1:length(tout)
%     calkaUchybu = calkaUchybu + (pi/4 - regulator1.signals.values(i,1))^2;
% end

% [P_opt] = fminsearch(@(x) wskaJak1(x), [P0, I0]);
% 
% P = P_opt(1);
% I = P_opt(2);
% T_sim = 50;

% [Nastawy] = fminsearch(@(x) wskaJak4(x), [P0, I0]);
% P = Nastawy(1);
% I = Nastawy(2);
% T_sim = 50;
% sim('modelJedenRegulator');
% Q = sum(uchyb.signals.values.^2);
