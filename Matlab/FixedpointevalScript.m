global tolerance maxits
tolerance = 1e-6;
maxits = 30;
a = 0;
global syms x F
F = cos(x)/exp(x);
[rootapprox, status] = Fixedpointeval(F, a);
switch status
    case - 1
        disp('Root finding failed')
    otherwise
        s = sprintf("The approximate root %d found in %d number of iterations", rootapprox, status);
        disp(s)
end
