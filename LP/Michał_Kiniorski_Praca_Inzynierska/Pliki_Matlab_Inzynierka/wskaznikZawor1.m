function blad =wskaznikZawor1(parametry)
    global C1;
    global x01;
    global pomiar_zawor1;
    C1=parametry(1);
    x01=parametry(2);
    pomiar=pomiar_zawor1;
    sim('identyfikacja_zawor1_reczny.slx');
    blad = sum((pomiar-H1.signals.values).^2);
end