function blad =wskaznikZawor2alfa(parametry)
    global C2a;
    global x02a;
    global alfa2;
    global pomiar_zawor2a;
    C2a=parametry(1);
    x02a=parametry(2);
    alfa2=parametry(3);
    pomiar=pomiar_zawor2a;
    sim('identyfikacja_zawor2_reczny_alfa.slx');
    blad = sum((pomiar-H2a.signals.values).^2);
end