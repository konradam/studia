function dx2 = rhs(x2,u)
% przyk�ad funkcji dla zbiornika �rodkowego
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

x2=max(x2,0);
S2=w*(((b-a)/H)*x2+a);
dx2=((c1*x1.^a1)-(c2*x2.^a2))/S2;
end
