function blad =wskaznikZawor1alfa(parametry)
    global C1a;
    global x01a;
    global alfa;
    global pomiar_zawor1a;
    C1a=parametry(1);
    x01a=parametry(2);
    alfa=parametry(3);
    pomiar=pomiar_zawor1a;
    sim('identyfikacja_zawor1_reczny_alfa.slx');
    blad = sum((pomiar-H1a.signals.values).^2);
end