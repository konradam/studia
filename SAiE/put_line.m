function [ ] = put_line( t_p, percent, color )
%put_line Rysuje linie na wykresie wskaszuj¹ce dany punkt
%   Wysokosc linii 0-1

hold on
% pionowa
y = linspace(0,percent,100);
x = ones(1,100)*t_p;
line(x,y, 'LineStyle', '--', 'Color', color);

% pozioma
y = ones(1,100)*percent;
x = linspace(0,t_p,100);
line(x,y, 'LineStyle', '--', 'Color', color);
hold off

end

