function Q = wskaznikJakosci(params)

    pompaPWM = params(1);
    zaworPWM = params(2);
    T_sim = 50;
    h0 = 20;
    ref = 20;
    load('parametryWielomianuPWMPompy.mat')
    load('parametryWielomianuPWMZaworu.mat')
    load('parametryWielomianuC1Zaworu.mat')
    load('parametryWielomianuC2Zaworu.mat')
    pompaP1 = p1;
    
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('modelZbiornik',[0 T_sim], options);

    Q = sum(uchyb.signals.values.^2);
 
end