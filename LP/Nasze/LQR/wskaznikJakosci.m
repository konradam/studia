function Q = wskaznikJakosci(params)

    pompaPWM = params(1);
    zaworPWM = params(2);
    T_sim = 50;
    h0 = 20;
    ref = 20;
    
    addpath('D:\Studia_repo\studia\LP\Nasze\model')
    %wczytanie danych do modelu
    skryptDoUruchamianiaModelu
    
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('model_Zbiornik_wsk',[0 T_sim], options);

    Q = sum(uchyb.signals.values.^2);
 
end