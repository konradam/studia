function lin_1=linearka_1(A,B,C,D,q,zbiornikix)

options = simset('SrcWorkspace','current');
sim('linearyzacja_mini',[],options);

lin_1=0;
for i=1:1:50001
    lin_1=(zbiornikix(i,1)-stany(i,1))^2 + (zbiornikix(i,2)-stany(i,2))^2 + (zbiornikix(i,3)-stany(i,3))^2 + lin_1;
end