function Q = wskaznikJakosciCzas(params)

    P1 = params(1);
    I1 = params(2);
    D1 = params(2);
    P2 = params(1);
    I2 = 0;
    D2 = params(2);
    T_sim = 200;
    h0 = 30;
    ref = 5;
    
    addpath('D:\Studia_repo\studia\LP\Nasze\model')
    %wczytanie danych do modelu
    skryptDoUruchamianiaModelu
    
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('model',[0 T_sim], options);
    data = poziom.signals.values(:,1);
    Q = T_sim;
    
    for i = 1:length(data)
        if (data(i) >= ref - 0.05 &&  data(i) <= ref + 0.05 && flaga == 0)
            Q = poziom.time(i);
            flaga = 1;
        elseif ~(data(i) >= ref - 0.05 &&  data(i) <= ref + 0.05)
            flaga = 0;
        end
    end
 
end