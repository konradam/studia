%Rysowanie sterowan na wspolnym wykresie


figure();
for i=1:5
    hold on;
plot(sterowanie_czas(:,i),sterowanie_regulator(:,i),'LineWidth',2);
end

hold on;
%title('Przebiegi symulacyjne sterowania  ','FontSize',16);
legend('przebieg sterowania dla trybu 1','przebieg sterowania dla trybu 2','przebieg sterowania dla trybu 3','przebieg sterowania dla trybu 4','przebieg sterowania dla trybu 5','FontSize',16);
grid;
set(gca,'fontsize',16);
set(gcf,'color','white');
xlabel('Czas [s]','FontSize',16);
ylabel('Sterowanie ','FontSize',16);
hold off;
