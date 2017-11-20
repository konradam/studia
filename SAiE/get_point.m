function [ t_p ] = get_point( t,y, percent)
%get_point Zwraca czas dla zadanej wartoœci
%   Na razie zwyk³a minimalizacja

t_p = t((abs(y-percent)==min(abs(y-percent))));

end

