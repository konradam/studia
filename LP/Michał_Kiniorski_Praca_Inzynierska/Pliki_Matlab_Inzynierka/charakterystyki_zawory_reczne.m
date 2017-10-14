close all;
load daneZawory_cz2.mat;
%%zawor reczny 1 przy pozycji zaznaczonej fioletowym markerem(poczatek
%%pokretla)
%kod do powtorzenia pomiaru 
%poziom =H1.signals.values(odkad chcesz mierzyc do konca); czas tak samo i
%odjac od czas_zawor(1);
poziom_zawor1_poprawiony=poziom_zawor1(1:810);  %40.45s
poziom_zawor2_poprawiony=poziom_zawor2(1:873);  %43.6s
poziom_zawor3_poprawiony=poziom_zawor3(1:826);  %41.25
czas_zawor1_poprawiony=czas_zawor1(1:810); 
czas_zawor2_poprawiony=czas_zawor2(1:873);
czas_zawor3_poprawiony=czas_zawor3(1:826);
figure();
plot(czas_zawor1_poprawiony,poziom_zawor1_poprawiony);
figure();
%%zawor reczny 2 przy pozycji zaznaczonej na czerwono
plot(czas_zawor2_poprawiony,poziom_zawor2_poprawiony);
%%zawor reczny 3 przy pozycji zaznaczonej na fioletowo(zewnetrzna strona
%%pokretla przy linii)
figure();
plot(czas_zawor3_poprawiony,poziom_zawor3_poprawiony);

%%wymiary dla zbiornika 2
b=40;
c=10;
H2max=40;
%%wymiary dla zbiornika 3
R=40;
H3max=R;
