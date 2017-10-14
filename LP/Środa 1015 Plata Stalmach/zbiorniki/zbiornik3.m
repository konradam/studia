function z = zbiornik3(a2,a3,c2,c3,x2,x3,w,R)
    
    S3 = w*sqrt(2*R*x3-x3^2);
    z = (c2*(x2^a2)-c3*(x3^a3))/S3;

end