function f=SIR2(b)
%Assign a value to each parameter
beta=b(1);
gama=b(2);
S0=b(3);
y0=[S0,1,0];
N=8540000;
ts=1:1:37;
%The function values of the simulation model
[t,y]=ode45(@(t,y)SIR(t,y,beta,gama,N),ts,y0);
C=y(:,2)+y(:,3);
%The confirmed case numbers
Ca=numGet();
%The square value of the two norm
v=norm(Ca-C);
f=v^2;
end

