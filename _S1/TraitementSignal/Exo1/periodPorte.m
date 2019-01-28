function [f]=periodPorte(size, period, N, xt, a, b)

for n=1:N
    
    finded = 0;
    i = 0;
    
    if xt(n) > 0
        while i * period <= b
            x0 = i * period - size / 2;
            x1 = i * period + size / 2;

            if xt(n) > x0 && xt(n) < x1
                f(n) = 1;
                finded = 1;
                break;
            end
            
            i = i + 1;
        end
    else   
        while i * period >= a
            x0 = i * period - size / 2;
            x1 = i * period + size / 2;

            if xt(n) > x0 && xt(n) < x1
                f(n) = 1;
                finded = 1;
                break;
            end
            
            i = i - 1;
        end
    end
   
    if finded == 0
        f(n) = 0;
    end
end

% figure(4);
% plot(xt, f);
% axis([-5, 5, -0.5, 1.5]);