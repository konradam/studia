%%
addpath('D:\Studia_repo\studia\LP\Nasze\model')
%wczytanie danych do modelu
skryptDoUruchamianiaModelu
h0 = 20;

xr = 20;
ur = [0.254860012262847 0.775110454488783];
% ur = [ 0.775110454488783 0.254860012262847];
zaworPWM = ur(2);
pompaPWM = ur(1);

[A B C D] = linmod('model_Zbiornik_Linmod', xr, ur);

Q = 10000;
R = [10 0; 0 10];
K = lqr(A,B,Q,R);