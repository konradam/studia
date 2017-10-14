%skrypt s³u¿acy do linearyzacji modelu

%najpierw korzystam z funkcji trim ktora znajduje punkt równawagi 
%kolejne parametry to: wektor stanu, wejscia, wyjscia, i ograniczenia
%kolejno na te parametry czy maja sie zmieniac czy nie ( ja chce aby moj
%poziom w 3 zbiorniku byl 10
[x,u,y,dx]=trim('model_matematyczny',[],[0.18],[0; 0; 10 ],[],[],[3]);

%funkcja sluzaca do linearyzacji zwraca macierz stanu po linearyzacji
[A,B,C,D]=linmod('model_matematyczny',x,u);
B=[0.0065 ; 0; 0;0];
SYS=ss(A,B,C,D);