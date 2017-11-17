clear all;
close all;

load('regulator1.mat');
load('sterowanie.mat');
load('ref.mat');

% t = regulator1.time;
x = sterowanie.signals.values(:,1)';
y = regulator1.signals.values(:,1)';

% x = x(1:5:end);
% y = y(1:5:end);

net = feedforwardnet(10);
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