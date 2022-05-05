function [rootapprox,status] = Fixedpointeval(fun,a)
global tolerance maxits
global syms x F
iterations = 0;
f_a = eval(subs(fun, x, a));
fdiff = diff(fun, x);
while iterations<maxits & abs(a - f_a)>tolerance
    iterations = iterations + 1;
    b = f_a;
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