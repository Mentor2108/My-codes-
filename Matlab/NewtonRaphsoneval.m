function [rootapprox,status] = NewtonRaphsoneval(fun,a)
global tolerance maxits
global syms x F
iterations = 0;
f_a = eval(subs(fun, x, a));
fdiff = diff(fun, x);
while iterations<maxits & abs(f_a)>tolerance
    iterations = iterations + 1;
    fdiff_a = eval(subs(fdiff, x, a));
    b = a-f_a/fdiff_a;
    a = b;
    f_a = eval(subs(fun, x, a));
end

switch iterations
    case maxits
        status = -1;
        rootapprox = NaN;
    otherwise
        status = iterations;
        rootapprox = a;
end