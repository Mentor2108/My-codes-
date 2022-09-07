clc
clear all
% Specify x range and number of points
 x0 = -5; x1 = 5; Nx = 301;
 % Specify y range and number of points
 y0 = -5; y1 =5; Ny = 301;
 % Construct mesh
 xv = linspace(x0,x1,Nx);
 yv = linspace(y0,y1,Ny);
 [x,y] = meshgrid(xv,yv);
 % Calculate z
 z = x + i*y;
 %Euler growth factor
 %g = 1 + z; % z=h*lambda
 %Rk2  growth factor
 %g = 1 + z+ z.^2/factorial(2); 
 %Rk4 growth factor
 g = 1 + z+ z.^2/factorial(2)+z.^3/factorial(3)+z.^4/factorial(4);   
 
 %Rk6 growth factor
 %g = 1 + z+ z.^2/factorial(2)+z.^3/factorial(3)+z.^4/factorial(4)+z.^5/factorial(5)+z.^6/factorial(6);  
 % Calculate magnitude of g
 gmag = abs(g);
 % Plot contours of gmag
 contour(x,y,gmag,[1 1],'r--'); 
 axis([x0,x1,y0,y1]);
 axis('square');
 xlabel('Real \lambda\Delta t');
 ylabel('Imag \lambda\Delta t');
 title('RK Methods') 
 grid on;

 