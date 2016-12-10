function theta = thetaCap(theta)

if( theta < -pi )
    theta = theta+2*pi;
elseif( theta > pi )
    theta = theta-2*pi;
end