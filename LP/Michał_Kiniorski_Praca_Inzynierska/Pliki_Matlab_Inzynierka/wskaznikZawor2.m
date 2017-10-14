function blad =wskaznikZawor2(parametry)
    global C2;
    global x02;
    global pomiar_zawor2;
    C2=parametry(1);
    x02=parametry(2);
    pomiar=pomiar_zawor2;
    sim('identyfikacja_zawor2_reczny.slx');
    blad = sum((pomiar-H2.signals.values).^2);
end