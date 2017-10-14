function [blad1,blad2,blad3] =wskaznikLQ(parametry)
    
    global q11;
    global q22;
    global q33;
    global R1;
    global K;
    global A;
    global B;
    q11=parametry(1);
    q22=parametry(2);
    q33=parametry(3);
    R1=parametry(4);
   
    
    
    Q=[q11 0 0; 0 q22 0; 0 0 q33];
    R=abs(R1);
    A_pomoc=A;
    B_pomoc=B;
    
    [K,S,eig]=lqr(A_pomoc,B_pomoc,Q,R,0);
    sim('Regulator.mdl');
    disp(R);
    blad1 = q_lqr(end);
    blad2 = sum(uchyb2.signals.values).^2;
    blad3 = sum(uchyb3.signals.values).^2;
end 