function [ ret ] = opt_pid( input )
global P I D
P = input(1);
I = input(2);
D = input(3);

sim('modelPID');
ret = jakosc(length(jakosc), 1);
end

