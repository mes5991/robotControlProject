%% Controller Testbed

%%
clear
close all
%%
path_vec = [0:100; %x-values
    zeros(1,101); %y-values
    zeros(1,101)]; %heading values
L = 4.5; %m, car length
%PD gain values
% kp = 1.5;
% kv = .001;
% ki = 0;

% PID gain values
% kp = 4;
% kv = .005;
% ki = 0.01;

kp = .07;
kv = 0;
ki = 0;

x0 = -5;
y0 = -5;
theta0 = 0;

sim PID_FUQROS

figure(1)
plot(pos_des(:,1),pos_des(:,2),'--r')
hold on
plot(pos_actual(:,1),pos_actual(:,2),'--')
axis equal
legend('Desired Position/Path','Actual Position')
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
