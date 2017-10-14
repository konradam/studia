function r=zbiornik_2(y2,C2,a2,h20)

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
sim('zbiornik2',[],options);
sim_h2=DDH2.signals.values(1:find(y2==y2(end)));


r=0;

for i=1:1:find(y2==y2(end));
 r=(y2(i)-sim_h2(i))^2 + r;
end
assignin('base','DH2',DDH2);

end