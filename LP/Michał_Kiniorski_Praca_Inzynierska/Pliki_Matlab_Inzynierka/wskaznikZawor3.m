function blad =wskaznikZawor3(parametry)
    global C3;
    global x03;
    global pomiar_zawor3;
    C3=parametry(1);
    x03=parametry(2);
    pomiar=pomiar_zawor3;
    sim('identyfikacja_zawor3_reczny.slx');
    blad = sum((pomiar-H3.signals.values).^2);
end