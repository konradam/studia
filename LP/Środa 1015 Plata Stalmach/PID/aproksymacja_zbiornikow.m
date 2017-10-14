%aproksymacja zbiornikow
zbiornikx_1=zbiorniki.signals(1).values;
zbiornikx_2=zbiorniki.signals(2).values;
zbiornikx_3=zbiorniki.signals(3).values;
zbiornikix=[zbiornikx_1 zbiornikx_2 zbiornikx_3];
czas_zbiorniki=zbiorniki.time;
% zbiornik_1_apro=zbiorniki_apro.signals(1).values;
% zbiornik_2_apro=zbiorniki_apro.signals(2).values;
% zbiornik_3_apro=zbiorniki_apro.signals(3).values;
% zbiornikix_apro=[zbiornik_1_apro zbiornik_2_apro zbiornik_3_apro];
% czas_zbiorniki_apro=zbiorniki_apro.time;

%aproksymacja 1 zbiornika
% k1=zbiornikx_1(end)/q;
% T1=(max(find(zbiornikx_1<=0.9*max(zbiornikx_1)))/100-max(find(zbiornikx_1<=0.1*max(zbiornikx_1)))/100)/3.3;
% 
% 
% %aproksymacja 2 zbiornika
% k2=zbiornikx_2(end)/h1;
% T2=(max(find(zbiornikx_2<=0.9*max(zbiornikx_2)))/100-max(find(zbiornikx_2<=0.1*max(zbiornikx_2)))/100)/3.3;
% 
% 
% %aproksymacja 3 zbiornika
% k3=zbiornikx_3(end)/h2;
% T3=(max(find(zbiornikx_3<=0.9*max(zbiornikx_3)))/100-max(find(zbiornikx_3<=0.1*max(zbiornikx_3)))/100)/3.3;

% xx10=[k1 T1];
% fun_zbior1=@(xx1)wylicz_apro_zbior1(czas_zbiorniki,zbiornikix,zbiornikix_apro,xx1(1),xx1(2),k2,T2,k3,T3,q);
% xx1=fminsearch(fun_zbior1,xx10);
% k1=xx1(1);
% T1=xx1(2);
%k2=xx1(3);
%T2=xx1(4);
%k3=xx1(5);
%T3=xx1(6);