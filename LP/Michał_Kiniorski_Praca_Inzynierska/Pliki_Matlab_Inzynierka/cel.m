function q=cel(p,tm,ym)
global nr_zb;
c=p(1); al=p(2); x0=p(3);
[t1,x1] = ode45(@(t,x) rhs(t,x,c,al,nr_zb),tm,x0);
e=x1(:,1)-ym;
q=e;