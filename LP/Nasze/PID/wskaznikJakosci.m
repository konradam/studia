function Q = wskaznikJakosci(params)

    P1 = params(1);
    I1 = 0;
    D1 = params(2);
    P2 = params(1);
    I2 = 0;
    D2 = params(2);
    T_sim = 300;
    h0 = 30;
    ref = 5;
    
    addpath('D:\Studia_repo\studia\LP\Nasze\model')
    %wczytanie danych do modelu
    skryptDoUruchamianiaModelu
    
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('model',[0 T_sim], options);

    Q = sum(uchyb.signals.values.^2);
 
end