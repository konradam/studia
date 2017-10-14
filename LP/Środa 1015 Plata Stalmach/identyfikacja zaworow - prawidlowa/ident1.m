%czas=Lev.time;
%czas_zbior_1=Lev.time;
%czas_zbior_2=Lev.time;
%czas_zbior_3=Lev.time;
%y1=Lev.signals(1).values;
%y2=Lev.signals(2).values;
%y3=Lev.signals(3).values;



u=0;
c=10;
a=35;
w=5;
R=36.4;
b=37;
h1max=35;
h2max=35;
h3max=35;
DH1=[];
DH2=[];
DH3=[];

%S3 = w*sqrt(2*R*x3-x3^2);
%y3 = (c2*(x2^a2)-c3*(x3^a3))/S3;
%zbiornik 1
x0=[10 0.1];
C1=30;
a1=0.5;
options=optimset('TolX',0.01,'PlotFcns',@optimplotfval);
fun=@(x)zbiornik_1(y1,x(1),x(2),h10);
x=fminsearch(fun,x0,options);
  

%zbiornik 2
x01=[10 0.1 ];
C2=30;
a2=0.5;

fun1=@(x1)zbiornik_2(y2,x1(1),x1(2),h20);
x1=fminsearch(fun1,x01);

%zbiornik 3
x02=[10 0.1 ];
C3=30;
a3=0.5;

fun2=@(x2)zbiornik_3(y3,x2(1),x2(2),h30);
x2=fminsearch(fun2,x02);
C1=x(1);
a1=x(2);
C2=x1(1);
a2=x1(2);
C3=x2(1);
a3=x2(2);

figure(1)    
plot(czas1,y1,czas1,DH1.signals.values(1:find(y1==y1(end)))) 
 figure(2)    
plot(czas2,y2,czas2,DH2.signals.values(1:find(y2==y2(end))))
figure(3)    
plot(czas3,y3,czas3,DH3.signals.values(1:find(y3==y3(end))))