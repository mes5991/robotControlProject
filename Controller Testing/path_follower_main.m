%% Path Follower
% Runs simulation of dubins car model being controlled by a modified
% hoffman follower. Three path choices are available: straight line, circle
% path, and a sin wave. The path coice can be changed in the "path" block
% of the path_follower_main simulink file.

%%
clear
close all
%% Simulation

L = 4.5; %m, car length
% PID gain values for modified hoffman
kp = 1;
kv = .05;
ki = 0;

%Gain values for hoffman follower
% kp = .7;
% kv = 0;
% ki = 0;


%Initial vehicle conditions
x0 = 0;
y0 = 0;
theta0 = pi/6;

%Run simulation
sim path_follower_main

%Store data
% locationErrorHoffman = locationError;
% headingErrorHoffman = headingError;
% phiHoffman = phi;


%% Plotting
desiredPath = reshape(desiredPath(1,:),[],3);

%Position
figure(1)
plot(chosenPath(1:500:end,1),chosenPath(1:500:end,2),'xr')
hold on
plot(desiredPath(:,1),desiredPath(:,2),'--')
plot(actualPath(:,1),actualPath(:,2),'g')
axis equal
for i = 1:10000:length(theta.time)
    timeStamp = [num2str(theta.time(i)), 's'];
    text(actualPath(i,1),actualPath(i,2),timeStamp)
end
legend('Chosen Path','Desired Path','Actual Path')
title('Position')
xlabel('x position: meters')
ylabel('y position: meters')
grid on
set(gca,'fontsize',20)
hold off



% saveas(1, 'position','png')

%Heading
figure(2)
plot(theta.time,theta.signals.values)
title('Heading')
xlabel('Time')
ylabel('Radians')
grid on
% saveas(2, 'heading','png')

%Error plots
figure(3)
subplot(3,1,1)
plot(locationError.time, locationError.signals.values)
title('Euclidean Distance to Closest Point Along Path')
xlabel('Time')
ylabel('Meters')
grid on

subplot(3,1,2)
plot(headingError.time, headingError.signals.values)
title('Heading Error w.r.t Closest Point Along Path')
xlabel('Time')
ylabel('Radians')
grid on

subplot(3,1,3)
plot(phi.time,phi.signals.values)
title('Steering Angle Control Input')
xlabel('Radians')
ylabel('Time')
grid on
% saveas(3, 'error and steering angle','png')

%Position error subplots
figure(4)
subplot(2,1,1)
plot(locationError.time, locationError.signals.values)
title('Euclidean Distance to Closest Point Along Path - Modified Hoffman')
xlabel('Time')
ylabel('Meters')
grid on
set(gca,'fontsize',20)

subplot(2,1,2)
plot(locationErrorHoffman.time, locationErrorHoffman.signals.values)
title('Euclidean Distance to Closest Point Along Path - Hoffman')
xlabel('Time')
ylabel('Meters')
grid on
set(gca,'fontsize',20)


%Heading error subplots
figure(5)
subplot(2,1,1)
plot(headingError.time, headingError.signals.values)
title('Heading Error w.r.t Closest Point Along Path - Modified Hoffman')
xlabel('Time')
ylabel('Radians')
grid on
set(gca,'fontsize',20)

subplot(2,1,2)
plot(headingErrorHoffman.time, headingErrorHoffman.signals.values)
title('Heading Error w.r.t Closest Point Along Path - Hoffman')
xlabel('Time')
ylabel('Radians')
grid on
set(gca,'fontsize',20)

%Phi input subplots
figure(6)
subplot(2,1,1)
plot(phi.time,phi.signals.values)
title('Steering Angle Control Input - Modified Hoffman')
xlabel('Radians')
ylabel('Time')
grid on
set(gca,'fontsize',20)

subplot(2,1,2)
plot(phiHoffman.time,phiHoffman.signals.values)
title('Steering Angle Control Input - Hoffman')
xlabel('Radians')
ylabel('Time')
grid on
set(gca,'fontsize',20)