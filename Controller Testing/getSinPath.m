function [x,y,phi] = getSinPath(x, a, w)

x = 0:.001:x;
y = a*sin(w*x);
slope = cos(x);
phi = atan(slope);

end