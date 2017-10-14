% y1=Lev.signals(1).values;
% y2=Lev.signals(2).values;
% y3=Lev.signals(3).values;

h_noise_u=0.2;
h_noise_d=1.5;
%% y1
czas1=0:0.01:(size(y1)-1)/100;
czas1=czas1';
% Najpierw znajduje wartoœæ maksymaln¹ y1
% Potem odejmuje h_noise zeby pominac szumy z wykresu
% Przypisuje indeksy wykresu ponad granic¹ max(y1)-h_noise
% I biorê ten najbardziej z prawej
index1u=find(y1>(max(y1)-h_noise_u));
index1d=find(y1>h_noise_d);
% Rysuje od tego punktu
figure(1);

czas1=czas1(max(index1u):max(index1d));
y1=y1(max(index1u):max(index1d));
plot(czas1,y1);
% ten punkt bêdzie te¿ naszym x10 do identyfikacji 
h10=max(y1);
%% y2

%analogicznie
czas2=0:0.01:(size(y2)-1)/100;
czas2=czas2';

index2u=find(y2>(max(y2)-h_noise_u));
index2d=find(y2>h_noise_d);

czas2=czas2(max(index2u):max(index2d));
y2=y2(max(index2u):max(index2d));
figure(2);
plot(czas2,y2);

h20=max(y2);
%% y3

%analogicznie
czas3=0:0.01:(size(y3)-1)/100;
czas3=czas3';

index3u=find(y3>(max(y3)-h_noise_u));
index3d=find(y3>h_noise_d);

czas3=czas3(max(index3u):max(index3d));
y3=y3(max(index3u):max(index3d));
figure(3);
plot(czas3,y3);

h30=max(y3);