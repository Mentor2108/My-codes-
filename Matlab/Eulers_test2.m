clc
clear all

f=@(x,y) 1-y./x; fx=@(x,y) y./x.^2; fy=@(x,y) -1./x;
ex=@(x) x./2+1./(2*x);

a=1; b=6; n=50; h=(b-a)/n; x=a:h:b; x=x';
u=zeros(length(x),1); u(1)=1;

for i=1:length(x)-1
    %Euler's
    %u(i+1)=u(i)+h*f(x(i),u(i)); 
    
    %Taylors method of order 2
    u(i+1)=u(i)+h*f(x(i),u(i))+(h^2/2)*(fx(x(i),u(i))+fy(x(i),u(i))*f(x(i),u(i))); % Eulers
    
    %Rk2
%     k1=h*f(x(i),u(i)); 
%     k2=h*f(x(i)+h,u(i)+k1);
%     u(i+1)=u(i)+0.5*(k1+k2);

% %Rk4
%     k1=h*f(x(i),u(i)); 
%     k2=h*f(x(i)+h/2,u(i)+k1/2);
%     k3=h*f(x(i)+h/2,u(i)+k2/2);
%     k4=h*f(x(i)+h,u(i)+k3);
%     u(i+1)=u(i)+(k1+2*k2+2*k3+k4)/6;

end
subplot(1,2,1)
plot(x,u,'k--');
hold on;
plot(x,ex(x),'ro');
hold off;

subplot(1,2,2)
plot(x,abs(u-ex(x)),'k--');

