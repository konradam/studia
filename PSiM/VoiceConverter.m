function s = VoiceConverter(x, N)
% N = length(x);
Mlen = 240;
Mstep = 180;
Np = 10;
gdzie = 181;

lpc = [];
s = [];
% ss = [];
ss = zeros(1, 180);
bs = zeros(1, Np);
Nramek = floor((N-240)/180+1);

R = zeros(Np);
rr = zeros(Np, 1);
r = zeros(1, Mlen);
T = 0;
% x = filter([1 -0.9735], 1, x);

for nr = 1:Nramek
    n = 1 + (nr - 1)*Mstep : Mlen + (nr - 1)*Mstep;
    bx = x(n);
    
    bx = bx - mean(bx);
    for k = 0 : Mlen - 1
        r(k+1) = sum(bx(1 : Mlen -k) .* bx(1 + k:Mlen));
    end
    
%    subplot(411); plot(n, bx); title('fragment sygna³u mowy');
%    subplot(412); plot(r); title('jego funckaj autokorelacji');

    offset = 20; 
    rmax = max(r(offset: Mlen));
    
    imax = find(r == rmax);
    if( rmax > 0.35*r(1)) 
        T = imax; 
    else
        T = 0;
    end
    
    if(mean(T) > 80)
        T = round(T/2);
    end
%     T
    rr(1:Np, 1) = (r(2:Np+1))';
    
    for m = 1:Np
        R(m,1:Np) = [r(m:-1:2) r(1:Np - (m - 1))];
    end
    
    a = -inv(R)*rr;
    wzm = r(1)+r(2:Np+1)*a;
    H = freqz(1,[1;a]);
    
    T = 50;
    if(mean(T)~=0)
        gdzie = gdzie - Mstep;
    end
    
    for n = 1:180
        if( mean(T) == 0)
            pob = 2*(rand(1,1)-0.5);
            gdzie = 271;
        else
            if(n == gdzie)
                pob =1;
                gdzie = gdzie + mean(T);
            else
                pob = 0;
            end
        end
        ss(n) = wzm*pob-bs*a;
        bs = [ss(n) bs(1:Np-1)];
    end
    
    s = [s ss];
end