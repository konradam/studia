function Q = wskaJak1(params)
    R = 2;
    k = 0.1;
    ke = 5;
    mr = 5;
    r = 0.5;
    mw = 0.5;
    L = 0.1;

    %moment bezwladnosci ramienia
    Jr = 1/3*mr*r*r;

    %moment bezw�adno�ci bez wody
    J1 = Jr;

    %moment bezw�adno�ci z wod�
    J2 = Jr + mw * r*r;


    P = params(1);
    I = params(2);
    
    T_sim = 50;
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('modelJedenRegulator',[0 T_sim], options);
    if I < 0
        Q = sum(uchyb.signals.values.^2) + 500;
    else
        Q = sum(uchyb.signals.values.^2);
    end
    


end