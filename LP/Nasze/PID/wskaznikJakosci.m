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
    
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('model_PID',[0 T_sim], options);

    Q = sum(uchyb.signals.values.^2) + sum(zawor.signals.values)*10000;
 
end