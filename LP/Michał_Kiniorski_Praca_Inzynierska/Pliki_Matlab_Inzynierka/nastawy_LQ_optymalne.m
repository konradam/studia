%Wyznaczenie nastaw dla LQ

clear all; close all;
load wyznaczoneParametry25listopad;
load wymiary.mat;
linearyzacja;
disp(A);
 global q11;
 global q22;
 global q33;
 global R1;
 global A;
 global B;
 global K;
[parametry_LQ]=fminsearch(@wskaznikLQ,[10 1 30 38]);
