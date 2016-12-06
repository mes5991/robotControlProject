%% Controller Testbed

%%
clear
close all
%%
path_vec = [0:100; %x-values
    zeros(1,101); %y-values
    zeros(1,101)]; %heading values
L = 4.5; %m, car length

x0 = 10;
y0 = 10;
theta0 = -pi;

sim PID_FUQROS

figure
plot(pos_des(:,1),pos_des(:,2),'--r')
hold on
plot(pos_actual(:,1),pos_actual(:,2),'--')
axis equal

figure
plot(theta.time,theta.signals.values)

figure
plot(phi.time,phi.signals.values)
