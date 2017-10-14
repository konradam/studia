% charakterystyka pompa
h=9.5;
a=31;
w=5;
sterowanie=[0.3 0.35 0.4 0.45 0.5 0.55 0.6 0.65 0.7 0.75 0.8 0.85 0.9 0.95 1];
czas=[167.73 59.23 41.63 33.02 26.78 22.61 19.96 17.61 16.26 14.93 13.76 12.9 11.88 10.91 10.75];

objetosc=zeros(length(czas));
objetosc=objetosc(1,:)+a*w*h;

wydajnosc_pompa=objetosc./czas;

interpolacja_pompa=polyfit(sterowanie,wydajnosc_pompa,3);
wektor=0.3:0.005:1;
krzywa_interpolacja=polyval(interpolacja_pompa,wektor);
figure();
plot(wektor,krzywa_interpolacja,'LineWidth',2);
hold on;
plot(sterowanie,wydajnosc_pompa,'k*','MarkerSize',14);
axis([0.3 1 0 140 ]);
legend('w','q','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Wspó³czynnik wype³nienia PWM ','FontSize',16);
ylabel('Wydajnoœæ pompy [cm^3/s]','FontSize',16);
hold off;