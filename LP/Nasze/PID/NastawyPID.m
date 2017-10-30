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

    P1 = 0.923296300060795; 
    I1 = 1.012929016515024; 
    D1 = 1.051744042729325;

T_sim = 300;
h0 = 15;
ref = 10;

%wczytanie danych do modelu
skryptDoUruchamianiaModelu
