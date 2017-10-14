%czas=Lev.time;
y1_uciety=y1(400:size(y1),1);
czas_zbior_1=Lev.time(1:size(y1));
czas_zbior_2=Lev.time(1:size(y1_uciety));
%y1=Lev.signals(1).values;
%y2=Lev.signals(2).values;
%y3=Lev.signals(3).values;
% k=1;
% [p q]=size(y1_uciety);
%     for i=1:p
%         if czas_zbior_2(i,1)==round(czas_zbior_2(i,1))
%             y1_nowy(k)=y1_uciety(i,1);
%             czas_nowy(k)=czas_zbior_2(i,1);
%             k=k+1
%         end
%     end
plot(czas_zbior_2,y1_uciety);
t=[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 ];
y=[17.9698487268902 17.3243675116677 16.7174708027558 16.1073554307504 15.4986014256442 14.9397701787230 14.3196212581678 13.7372190526856 13.1538378637739 12.6192666061270 12.0465287676978 11.4885554245889 10.9682415504915 10.4132528664346 9.90667730396347 9.40290178388223 8.88678105304806 8.37588948319297 7.91182840787570 7.41986017201406 6.92509691153461 6.49081679462100 6.01973290526346 5.57214478874129 5.12825498078094 4.71104182792321 4.30649725977715 3.88628751012095 3.50051997487794 3.11343980821482 2.74016814825143 2.36134813931261];
u=0;
c=31;
a=31;
w=5;
R=36.4;
b=37;
h1max=35;
h2max=35;
h3max=35;
[xx fctval] = fminsearch('minfunc', [100 28])
for i=1:32
   y_nnno(i)= 1/(((xx(1)*i)/155 + 20^(1 - xx(2))/(xx(2) - 1))*(xx(2) - 1))^(1/(xx(2) - 1));
end
plot(t,y_nnno);
hold on
plot(t,y,'r');
syms h2(t) c2 a2
eqn = diff(h2,t) == -(c2*h2^a2)/w*(((b-a)/h2max)*h2+a);
cond = h2(0) == 18;
x1Sol(t) = dsolve(eqn,cond)

%dx1=(0-c1*(x1.^a1))/(c*w);
% x1Sol(t) = 1/(((c1*t)/155 + 20^(1 - a1)/(a1 - 1))*(a1 - 1))^(1/(a1 - 1));
% syms x y
% f = symfun(x + y, [x y])


% syms C1 C2 C3 a1 a2 a3 h1(t) h2(t) t;
% j=sym('j',[1;2]);
% S2=c*w+(h2/h2max)*b*w;
% %zbiornik 1
% %Dh1=diff(h1,t) == (u-C1*sqrt(h1))/(c*w);
% Dh1='Dh1=(0-C1*h1^a1)/(31*5)';
% %h10 = h1(0) == 20;
% h10='h1(0)=20';
% rozw_h1=dsolve(Dh1,h10);
% %t=czas1;
% %h1=y1;
% %aaaa1=subs(deqn);
% %zbiornik 2
% eqn1=diff(h2,t) == -(C2*sqrt(h2))/S2;
% Dh2=-(C2*h2^a2)/(31*5+(h2/35)*37*5);
% %cond1= h2(0) == 20;
% h20='h2(0)=20';
% 
% %rozw_h2=dsolve(Dh2,h20);
% 
% %rozw_h2_imp=(h2*(1085*a2 - 37*h2 + 37*a2*h2 - 2170))/h2^a2 == (7*C2*t + (20/20^a2*(1825*a2 - 2910))/(a2^2 - 3*a2 + 2))*(a2^2 - 3*a2 + 2);
% %rozw_h2_imp=simplify(rozw_h2_imp);
% 
% 
% %t=czas_zbior_2;
% %h2=y2;
% aaaa=subs(Dh2,h2,y2(3000));
% 
% %zbiornik1 ale drugi wzor
% 
% 
% %tspan=[0 czas2(end)];
% %y0=20;
% %[t,h2]=ode45(@getter,tspan,y0);
% 
% %vpasimp=vpa(simp);
% %yout1= @(n)1/(((4499*n(1))/15500 + 20^(1 - n(2))/(n(2) - 1))*(n(2) - 1))^(1/(n(2) - 1));
% %n1=[20,0.1];
% %n=fminsearch(yout1,n1);
% %C1=n(1);
% %a1=n(2);
% %yout1=@(C1,a1)aaaa1
% %n1=[20,0.1];
% %[C1,a1]=fminsearch(yout1,n1);
% 
% yout2=@(n)-(31525197391593472*(3580664443831725/4503599627370496)^n(2)*n(1))/5018890180118761985;
% n2=[50,0.1];
% C2=fminsearch(yout2,n2);
% 
% 



%S3 = w*sqrt(2*R*x3-x3^2);
%y3 = (c2*(x2^a2)-c3*(x3^a3))/S3;


