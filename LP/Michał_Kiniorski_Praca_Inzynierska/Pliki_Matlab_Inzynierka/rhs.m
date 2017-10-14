function dx=rhs(t,x,c,al,zb)
% przyk³ad funkcji dla zbiornika œrodkowego
% a1=w*(b-a)/H,b1=w*a
dx=0;
a=31; b=40; cw=10;
w=5; H=40; R=40;
switch zb
    case 1
        S=a*w; 
    case 2
        a_1=cw*w;
        b_1=b*w/H;
        x=max(x,0);
        S=a_1+b_1*x;   
    case 3
        x=max(x,0);
        S=w*sqrt(R^2-(R-x)^2);
end;
        
dx=-c*x^al/S;