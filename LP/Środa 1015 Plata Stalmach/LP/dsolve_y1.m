function y1Sol = dsolve_y1( c1,a1,t )
%DSOLVE Summary of this function goes here
%   Detailed explanation goes here

y1Sol(t) = 1/(((c1*t)/155 + 18^(1 - a1)/(a1 - 1))*(a1 - 1))^(1/(a1 - 1));
end

