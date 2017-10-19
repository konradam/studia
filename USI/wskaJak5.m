function Q = wskaJak5(params)
    R = 2;
    k = 0.1;
    ke = 5;
    mr = 5;
    r = 0.5;
    mw = 0.5;
    L = 0.1;

    %moment bezwladnosci ramienia
    Jr = 1/3*mr*r*r;

    %moment bezw³adnoœci bez wody
    J1 = Jr;

    %moment bezw³adnoœci z wod¹
    J2 = Jr + mw * r*r;


    P = params(1);
    I = params(2);
    
    T_sim = 50;
    options = simset('SrcWorkspace','current','DstWorkspace','current');
    sim('modelzWoda',[0 T_sim], options);
    
    przysp = regulator2.signals.values(:,4);
    kara = 0;
    for i = 1:length(przysp)
       if (przysp(i) >= 0.1 ||  przysp(i) <= -0.1)
         kara = kara + 500;
       end
    end
    
    Q = sum(uchyb2.signals.values.^2) + kara;


end