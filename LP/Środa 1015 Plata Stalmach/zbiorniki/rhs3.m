function dx3 = rhs(x3,u)
% przyk³ad funkcji dla zbiornika œrodkowego
a=10;
b=44.5;
c=25;
w=3.5;
H=35;
R=36.4;

a1=0.5;
c1=19.01;
a2=0.5;
c2=32.45;
a3=0.5;
c3=32.45;

x3=max(x3,0);
S3 = w*sqrt(2*R*x3-x3^2);
dx3 = (c2*(x2^a2)-c3*(x3^a3))/S3;
end
