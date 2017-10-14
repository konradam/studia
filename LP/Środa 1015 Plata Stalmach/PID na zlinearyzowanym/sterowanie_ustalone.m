%ustalanie sterowania dla zadanego stanu ustalonego danego zbiornika

syms h2r h1r qr;
%h1=10;
%h2=10;
h3=10;
n=3;
for i=1:1:3
switch n
    case 1
        q=vpasolve(0==qr-C1*h1^a1,qr);
        q=vpa(q);
        q=double(q);
    case 2
        h1=vpasolve(0==C1*h1r^a1-C2*h2^a2,h1r);
        h1=vpa(h1);
        h1=double(h1);
        n=1;
    case 3
        h2=vpasolve(0==C2*h2r^a2-C3*h3^a3,h2r);
        h2=vpa(h2);
        h2=double(h2);
        n=2;
end
end


%dla odpowiedniego stanu ustalonego jest to inercja !!