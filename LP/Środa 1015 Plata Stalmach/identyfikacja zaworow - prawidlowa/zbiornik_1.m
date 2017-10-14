function r=zbiornik_1(y1,C1,a1,h10)

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
sim('zbiornik1',[],options);
sim_h1=DDH1.signals.values(1:find(y1==y1(end)));

r=0;

for i=1:1:find(y1==y1(end))
 r=(y1(i)-sim_h1(i))^2 + r;
end
assignin('base','DH1',DDH1);


end