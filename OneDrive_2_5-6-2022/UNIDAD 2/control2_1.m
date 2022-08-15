    close all

%     num1=2*20000*[1 1];
%     den1=conv([1 70 1000],[1 4 10]);
%     grid
%     Gs=tf(num1,den1);
%     Gz=c2d(Gs,0.0005,'ZOH');     
%     step(Gs,Gz)
%     figure
%     margin(Gs)
%     %bode(Gs)
%     grid
%     figure
%     margin(Gz)
%     %bode(Gz)
%     grid
%     figure
%     bode(Gs,Gz)
%     grid

    
%     num1=80*[1 1];
%     den1=conv([1 10 20],[1 4 10]);
%     Gs1=tf(num1,den1);
%     Gz1=c2d(Gs1,0.0001,'Tustin');
%     rlocus(Gs1)
%     figure
%     margin(Gs1)
%     grid
%     title('Sistema continuo')
%     figure
%     margin(Gz1)
%     grid
%     title('Sistema discreto')
%     figure
%     nyquist(Gs1)

% num2=90000*[1 -1];
% den2=conv([1 100],[1 5 100]);
% den2=conv(den2,[1 0.1]);
% Gs2=tf(num2,den2);
% Gz2=c2d(Gs2,0.0001,'ZOH');
% figure
% rlocus(Gs2)
% figure
% margin(Gs2)
% grid
% figure
% margin(Gz2)
% grid
% figure
% nyquist(Gs2)


num3=60000*[1 2 1];
den3=conv([1 5 -100],[1 0.1]);
den3=conv(den3,[1 100]);
Gs3=tf(num3,den3);
Gz3=c2d(Gs3,0.0001,'ZOH');
figure
rlocus(Gs3)
figure
margin(Gs3)
grid
figure
%margin(Gz3)
bode(Gz3)
grid
figure
nyquist(0.25*num3,den3)