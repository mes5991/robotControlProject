%% Controller Testbed

%%
clear
close all
%%

L = 4.5; %m, car length
%PD gain values
% kp = 1.5;
% kv = .001;
% ki = 0;

% PID gain values
kp = 2;
kv = 1;
ki = 0;

% kp = 50;
% kv = 10;
% ki = 1;

x0 = 0;
y0 = 0;
theta0 = pi/6;

sim path_follower_main

desiredPath = reshape(desiredPath(1,:),[],3);

figure(1)
plot(chosenPath(:,1),chosenPath(:,2),'r')
hold on
plot(desiredPath(:,1),desiredPath(:,2),'--')
plot(actualPath(:,1),actualPath(:,2),'g')
axis equal
for i = 1:1000:length(theta.time)
    timeStamp = num2str(theta.time(i));
    text(actualPath(i,1),actualPath(i,2),timeStamp)
end
legend('Chosen Path','Desired Path','Actual Path')
title('Position')
grid on
hold off


figure(2)
plot(theta.time,theta.signals.values)
title('theta over time')
grid on

figure(3)
plot(phi.time,phi.signals.values)
title('phi over time')
grid on

figure(4)
plot(locationError.time, locationError.signals.values)
title('Error to closest point along path')
xlabel('Time')
ylabel('Meters I think')
grid on

figure(5)
plot(headingError.time, headingError.signals.values)
title('Heading error w.r.t closest point along path')
xlabel('Time')
ylabel('Radians')
grid on

