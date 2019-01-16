function [c, err, yc]=bisect(f, a, b, delta)
ya=subs(f,a);
yb=subs(f,b);
if ya*yb > 0
    disp('No se puede aplicar el algoritmo, dado que entre a y b no se produce un cambio de signo');
    c='ERROR',err='ERROR',yc='ERROR'
    return
end
maxl = 1+round((log(b-a)-log(delta))/log(2));
for k = 1 : maxl
    c = (a+b)/2;
    yc=subs(f,c);
    if yc == 0
        a = c;
        b = c;
    elseif yb*yc > 0
        b = c;
        yb = yc;
    else
        a = c;
        ya = yc;
    end
    if b-a < delta
        break
    end
end
c = (a+b)/2;
err = abs(a-b);
yc = subs(f,c);
end