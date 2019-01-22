function s = traprl(f, a, b, M)
    h = (b-a)/M;
    s = 0;
    for k = 1 : (M-1)
       x = a + h*k;
       s = s + subs(f,x);
    end
    s = h*(subs(f,a)+subs(f,b))/2 + h*s;
end