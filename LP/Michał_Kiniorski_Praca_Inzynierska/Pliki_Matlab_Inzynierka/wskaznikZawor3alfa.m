function blad =wskaznikZawor3alfa(parametry)
    global C3a;
    global x03a;
    global alfa3;
    global pomiar_zawor3a;
    C3a=parametry(1);
    x03a=parametry(2);
    alfa3=parametry(3);
    pomiar=pomiar_zawor3a;
    sim('identyfikacja_zawor3_reczny_alfa.slx');
    blad = sum((pomiar-H3a.signals.values).^2);
end