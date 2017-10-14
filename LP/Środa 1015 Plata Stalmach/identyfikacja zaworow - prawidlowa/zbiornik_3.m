function r=zbiornik_3(y3,C3,a3,h30)

u=0;
c=10;
a=35;
w=5;
R=36.4;
b=37;
h1max=35;
h2max=35;
h3max=35;

options = simset('SrcWorkspace','current');
sim('zbiornik3',[],options);
sim_h3=DDH3.signals.values(1:find(y3==y3(end)));

r=0;

for i=1:1:find(y3==y3(end))
 r=(y3(i)-sim_h3(i))^2 + r;
end
assignin('base','DH3',DDH3);

end