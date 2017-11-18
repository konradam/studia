function Q = wskaznikJakosci(params)

    P1 = params(1);
    I1 = params(2);
    D1 = params(3);
    P2 = params(1);
    I2 = 0;
    D2 = params(2);
    T_sim = 100;
    h0 = 5;
    ref = 30;
    
    addpath('D:\Studia_repo\studia\LP\Nasze\model')
    %wczytanie danych do modelu
    skryptDoUruchamianiaModelu
    
    %czas dyskretyzacji
    Td = 0.5;
    
    try
        options = simset('SrcWorkspace','current','DstWorkspace','current');
        sim('model_PID_dyskretny_pompa',[0 T_sim], options);
        Q = sum(uchyb.signals.values.^2)
    catch
        Q = inf;
    end
    
%     sterowanie_kara = 0;
%     for i = 2:length(sterowanie.signals.values)
%         sterowanie_kara = sterowanie_kara + (sterowanie.signals.values(i-1, 1)- sterowanie.signals.values(i, 1))^2;
%     end

%     Q = sum(uchyb.signals.values.^2) + sum(zawor.signals.values)*10000 + sterowanie_kara;
    
 
end