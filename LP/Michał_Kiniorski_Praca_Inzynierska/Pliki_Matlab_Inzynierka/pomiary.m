close all;
%%skalowanie czujnikow
%sensor1
czujnik1=[0.3281,0.6571,0.9751,1.2975,1.6131,1.9271];
poziom1=[5,10,15,20,25,30];
p1=polyfit(czujnik1,poziom1,1);
%sensor2
czujnik2=[0.3206,0.6472,0.9791,1.3076,1.6191,1.9424];
poziom2=[5,10,14.9,20,25,30];
p2=polyfit(czujnik2,poziom2,1);
%sensor3
czujnik3=[1.1948,1.3925,1.5958,1.8009,2.0041,2.2059];
poziom3=[5,9.9,15,20,25,30];
p3=polyfit(czujnik3,poziom3,1);

%charakterystyki statyczne czujników
figure();
plot(czujnik1,poziom1,'r-*','LineWidth',2);
hold on;
grid;
hold off;
figure();
plot(czujnik2,poziom2,'r-*','LineWidth',2);
hold on;
grid;
hold off;
figure();
plot(czujnik3,poziom3,'r-*','LineWidth',2);
hold on;
grid;
hold off;

%%wydajnosc pompy
a=31;
w=5;
h=10 %albo 10 w zaleznosci czy przyjmuje offset na poczatku czy nie
sterowanie=[ 0.18 0.2 0.25 0.3 0.35 0.4 0.45 0.5 0.55 0.6 0.65 0.7 0.75 0.8 0.85 0.9 0.95 1];
czas=[151.35,84.35,46.75,34.75,27.7,23.75,21, 18.9,17.5, 16.15,15.25,14.5,13.8,12.95,12.45,11.75,11.15,10.85];
objetosc=zeros(length(czas));
objetosc=objetosc(1,:)+a*w*h;

wydajnosc_pompa=objetosc./czas;

figure();
plot(sterowanie,wydajnosc_pompa);
grid;
interpolacja_pompa=polyfit(sterowanie,wydajnosc_pompa,5);
wektor=0.18:0.01:1;
krzywa_interpolacja=polyval(interpolacja_pompa,wektor);
figure();
hold on;
plot(sterowanie,wydajnosc_pompa,'r*');
plot(wektor,krzywa_interpolacja);
hold off;

%%zawor reczny 1 przy pozycji zaznaczonej fioletowym markerem(poczatek
%%pokretla)
%kod do powtorzenia pomiaru 
%poziom =H1.signals.values(odkad chcesz mierzyc do konca); czas tak samo i
%odjac od czas_zawor(1);
figure();
plot(czas_zawor1,poziom_zawor1);
figure();
%%zawor reczny 2 przy pozycji zaznaczonej na czerwono
plot(czas_zawor2,poziom_zawor2);
%%zawor reczny 3 przy pozycji zaznaczonej na fioletowo(zewnetrzna strona
%%pokretla przy linii)
figure();
plot(czas_zawor3,poziom_zawor3);

%%wymiary dla zbiornika 2
b=40;
c=10;
H2max=40;
%%wymiary dla zbiornika 3
R=40;
H3max=R;
