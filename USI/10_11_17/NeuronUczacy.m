clear all;
close all;

load('regulator1.mat');
load('sterowanie.mat');
load('ref.mat');
load('uchyb.mat');

% t = regulator1.time;
y = sterowanie.signals.values(:,1)';
x = regulator1.signals.values(:,1)';
uchyb = uchyb.signals.values(:,1)';
x = [x; ref.signals.values(:,1)'; [0 uchyb(1:end-1)]];
% x = x(1:5:end);
% y = y(1:5:end);

net = feedforwardnet(5);
% net = fitnet(10);
net = configure(net,x,y);
% net = init(net);
y1= net(x);

plot(y)
hold on
plot(y1)

legend('dane','neuron')
% view(net);

%%
net = train(net,x,y);
y2 = net(x);

figure()
plot(y)
hold on
plot(y2)

legend('dane','neuron')

% perf = perform(net,y,t)