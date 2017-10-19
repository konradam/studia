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

%moment bezw³adnoœci bez wody
J1 = Jr;

%moment bezw³adnoœci z wod¹
J2 = Jr + mw * r*r;
% 
% % A = [0 k/J; -ke/L -R/L];
% % B = [0; 1/L];
% % C = [1 0; 0 1];
% % D = [0; 0];
% 
%Nastawy regulatora
P0 = 20;
I0 = 0.03;
P = P0;
I = I0;
T_sim = 50;
sim('modelZWoda');

%Pierwszy wskaŸnik
Q1 = sum(uchyb.signals.values.^2);

%Drugi wskaŸnik
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

%Trzeci wskaŸnik
Q3 = sum(sterowanie.signals.values.^2)*T_sim;

%%
%Poszukiwanie P I dla minimalizacji 4 wskaŸnika 
[Nastawy] = fminsearch(@(x) wskaJak5(x), [P0, I0]);
P = Nastawy(1);
I = Nastawy(2);
sim('modelZWoda');

%Pierwszy wskaŸnik
Q14 = sum(uchyb.signals.values.^2);

%Drugi wskaŸnik
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

%Trzeci wskaŸnik
Q34 = sum(sterowanie.signals.values.^2)*T_sim;