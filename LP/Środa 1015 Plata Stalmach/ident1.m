czas=Lev.time;
%y1=Lev.signals(1).values;
%y2=Lev.signals(2).values;
y3=Lev.signals(3).values;
plot(czas,y3)
u=0;
c=31;
w=5;
yout1 = @(n)(u-n(1)*(20.^n(2)))/(c*w);
n1=[20,0.1];
n=fminsearch(yout1,n1);
%S2=w*(((b-a)/H)*x2+a);
%y2=((c1*x1.^a1)-(c2*x2.^a2))/S2;

%S3 = w*sqrt(2*R*x3-x3^2);
%y3 = (c2*(x2^a2)-c3*(x3^a3))/S3;


