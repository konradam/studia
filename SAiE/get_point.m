function [ t_p ] = get_point( t,y, percent)
%get_point Zwraca czas dla zadanej warto�ci
%   Na razie zwyk�a minimalizacja

t_p = t((abs(y-percent)==min(abs(y-percent))));

end

