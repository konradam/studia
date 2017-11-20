close all;
clear all;

L = 1;
M = [720 1764 1624 735 175 21 1];
sys = tf(L,M);

figure(1)
[y,t] = step(sys,0:0.01:80);
plot(t,y)
hold on
grid on
j=1;
k=1;

%% Strejc n = 2

for i=1:length(y)
   if(y(i) <= 0.264 + 0.0002 && y(i) >= 0.264 - 0.0002)
      tempTime02(j) = t(i);
      tempValue02(j) = y(i);
      j=j+1;
   elseif(y(i) <= 0.90 + 0.0002 && y(i) >= 0.90 - 0.0002)
      tempTime90(k) = t(i);
      tempValue90(k) = y(i);
      k=k+1;
   end
end

[mint02, it02] = min(abs(tempValue02-0.264));
t02 = tempTime02(it02);
[minT90, iT90] = min(abs(tempValue90-0.90));
T90 = tempTime90(iT90);
T2 = 0.34605*(T90 - t02);
tau2 = t02 - T2;

L2 = 1;
M2 = [T2^2 2*T2 1];
sys2 = tf(L2, M2, 'InputDelay', tau2);
hold on
[y2,t] = step(sys2,0:0.01:80,'r');
plot(t,y2);

%% Strejc n = 3
for i=1:length(y)
   if(y(i) <= 0.323 + 0.0002 && y(i) >= 0.323 - 0.0002)
      tempTime03(j) = t(i);
      tempValue03(j) = y(i);
      j=j+1;
   elseif(y(i) <= 0.90 + 0.0002 && y(i) >= 0.90 - 0.0002)
      tempTime90(k) = t(i);
      tempValue90(k) = y(i);
      k=k+1;
   end
end

[mint03, it03] = min(abs(tempValue03-0.323));
t03 = tempTime03(it03);
[minT90, iT90] = min(abs(tempValue90-0.90));
T90 = tempTime90(iT90);
T3 = 0.30099*(T90 - t03);
tau3 = t03 - 2*T3;

L3 = 1;
M3 = [T3^3 3*T3^2 3*T3 1];
sys3 = tf(L3, M3, 'InputDelay', tau3);
hold on
step(sys3,0:0.01:80,'r');

%% Strejc n = 4
for i=1:length(y)
   if(y(i) <= 0.353 + 0.0002 && y(i) >= 0.353 - 0.0002)
      tempTime04(j) = t(i);
      tempValue04(j) = y(i);
      j=j+1;
   elseif(y(i) <= 0.90 + 0.0002 && y(i) >= 0.90 - 0.0002)
      tempTime90(k) = t(i);
      tempValue90(k) = y(i);
      k=k+1;
   end
end

[mint04, it04] = min(abs(tempValue04-0.353));
t04 = tempTime04(it04);
[minT90, iT90] = min(abs(tempValue90-0.90));
T90 = tempTime90(iT90);
T4 = 0.27168*(T90 - t04);
tau4 = t04 - 3*T4;

L4 = 1;
M4 = [T4^4 4*T4^3 6*T4^2 4*T4 1];
sys4 = tf(L4, M4, 'InputDelay', tau4);
hold on
step(sys4,0:0.01:80,'r');

%% Strejc n = 5
for i=1:length(y)
   if(y(i) <= 0.371 + 0.0002 && y(i) >= 0.371 - 0.0002)
      tempTime05(j) = t(i);
      tempValue05(j) = y(i);
      j=j+1;
   elseif(y(i) <= 0.90 + 0.0002 && y(i) >= 0.90 - 0.0002)
      tempTime90(k) = t(i);
      tempValue90(k) = y(i);
      k=k+1;
   end
end

[mint05, it05] = min(abs(tempValue05-0.371));
t05 = tempTime05(it05);
[minT90, iT90] = min(abs(tempValue90-0.90));
T90 = tempTime90(iT90);
T5 = 0.25040*(T90 - t05);
tau5 = t05 - 4*T5;
% tau5 = 2.00160*t05 - 1.00160*T90;

L5 = 1;
M5 = [T5^5 5*T5^4 10*T5^3 10*T5^2 5*T5 1];
sys5 = tf(L5, M5, 'InputDelay', tau5);
hold on
step(sys5,0:0.01:80,'r');
