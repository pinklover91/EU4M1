function build(name)
% To build EasyLink C-mex S-functions

inc='-I./include';

cpp='./src/easylink.cpp';

lib='';
 
P=['mex ' inc ' ' name ' ' cpp ' ' lib];
disp(['Building ' name '...']);

eval(P);