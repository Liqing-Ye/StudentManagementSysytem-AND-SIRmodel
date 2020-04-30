function dydt = SIR(~,y,beta,gama,N)
%dydt(1)=dS/dt; dydt(2)=dI/dt; dy/dt(3)=dR/dt
%y(1)=S(t);y(2)=I(t);y(3)=R(t)
dydt=zeros(3,1);
dydt(1)=-(beta/N).*y(1).*y(2);
dydt(2)=(beta/N).*y(1).*y(2)-gama.*y(2);
dydt(3)=gama.*y(2);
end