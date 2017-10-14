U = [100 150 200];
T = [5 10 15];
Np = 3;

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
x0=0;
x1=0;
x2=0;
x3=0;

for i = 1 : Np
    u = U(i);
    sizex1=length(x1);
    sizex2=length(x2);
    sizex3=length(x3);
    x1 = rk4(@(x0,x1) zbiornik1(a1,c1,c,w,x1,u), x1(sizex1), 1/3, u, 15);
    x2 = rk4(@(x0,x1) zbiornik2(x1,x2), x2(sizex2), 1/3, u, 15);
    x3 = rk4(@(x2,x3) zbiornik3(a2,a3,c2,c3,x2,x3,w,R), x3(sizex3), 1/3, u, 15);
end
