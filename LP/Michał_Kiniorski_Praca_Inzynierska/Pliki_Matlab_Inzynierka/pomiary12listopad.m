close all;
%%pompa nowa charakterystyka
wielomian_pompa02=polyfit(tpompa02,hpompa02,1);
pompa02=polyval(wielomian_pompa02,tpompa02);

wielomian_pompa03=polyfit(tpompa03,hpompa03,1);
pompa03=polyval(wielomian_pompa03,tpompa03);

wielomian_pompa04=polyfit(tpompa04,hpompa04,1);
pompa04=polyval(wielomian_pompa04,tpompa04);

wielomian_pompa05=polyfit(tpompa05,hpompa05,1);
pompa05=polyval(wielomian_pompa05,tpompa05);

wielomian_pompa06=polyfit(tpompa06,hpompa06,1);
pompa06=polyval(wielomian_pompa06,tpompa06);

wielomian_pompa07=polyfit(tpompa07,hpompa07,1);
pompa07=polyval(wielomian_pompa07,tpompa07);

wielomian_pompa08=polyfit(tpompa08,hpompa08,1);
pompa08=polyval(wielomian_pompa08,tpompa08);

wielomian_pompa09=polyfit(tpompa09,hpompa09,1);
pompa09=polyval(wielomian_pompa09,tpompa09);

wielomian_pompa10=polyfit(tpompa10,hpompa10,1);
pompa10=polyval(wielomian_pompa10,tpompa10);
figure();
plot(tpompa10,hpompa10);
hold on;
plot(tpompa10,pompa10,'k','LineWidth',3);

k2=find(pompa02>=10);
k3=find(pompa03>=10);
k4=find(pompa04>=10);
k5=find(pompa05>=10);
k6=find(pompa06>=10);
k7=find(pompa07>=10);
k8=find(pompa08>=10);
k9=find(pompa09>=10);
k10=find(pompa10>=10);

a=31; %dlugosc
w=5;  %szerokosc
h=9.5; %wysokosc napelnionego zbiornika
sterowanie=[0.18 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1];
czas_wydajnosc=[149.35 tpompa02(k2(1)) tpompa03(k3(1)) tpompa04(k4(1)) tpompa05(k5(1)) tpompa06(k6(1)) tpompa07(k7(1)) tpompa08(k8(1)) tpompa09(k9(1)) tpompa10(k10(1))];
objetosc=zeros(length(czas_wydajnosc));
objetosc=objetosc(1,:)+a*w*h;

wydajnosc_pompa=objetosc./czas_wydajnosc;

figure();
%plot(sterowanie,wydajnosc_pompa);
grid;
interpolacja_pompa=polyfit(sterowanie,wydajnosc_pompa,3);
wektor=0.18:0.01:1;
krzywa_interpolacja=polyval(interpolacja_pompa,wektor);
figure();
hold on;
plot(sterowanie,wydajnosc_pompa,'r*');
plot(wektor,krzywa_interpolacja);
hold off;