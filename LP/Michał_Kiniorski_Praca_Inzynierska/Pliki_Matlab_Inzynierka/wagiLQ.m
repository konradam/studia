%Skrypt wyliczajacy wzmocnienie K dla regulatora LQ
%najpierw wywolanie skryptu do linearyzacji wokol punktu pracy
function [K,S,e]= wagiLQ(Q,R,N)
linearyzacja;
%Dobieranie macierzy wag Q karze stany a R wejscia
[K_par,S_par,e_par] = lqr(A,B,Q,R,N);
K=K_par;
S=S_par;
e=e_par;
