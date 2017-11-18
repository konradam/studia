%% wskaznik jakosci - uchybu
clear all;
close all;

addpath('D:\Studia_repo\studia\LP\Nasze\model')

%znalezione nastawy
% P1 = 1.089062371871661;
% I1 = .002562814996863;
% D1 = -0.001112798115117;
P2 = 30.027479029282310;
I2 = 0;
D2 = -0.189641732763578;

%     P1 = 0.923296300060795; 
%     I1 = 1.012929016515024; 
%     D1 = 1.051744042729325;

%testowanie zachowania regulatora z saturacj¹
% P1 = 1.169264453414924;
% I1 = 1.188808390089748;
% D1 = 0.782698545831011;

% P1 = 2.549593035622680;
% D1 = 0.475581237587761;

%znalezione w modelu bez zaworu
P1 = 1.559211858494873;
I1 = 5.687643061134081e-04;
D1 = 1.333293908881934;



T_sim = 300;
h0 = 5;
ref = 30;

%wczytanie danych do modelu
skryptDoUruchamianiaModelu
