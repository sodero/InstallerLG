%{
#include <stdio.h>
%}

%union { char c; }

%%
s:      '(' s ')'         { printf("not empty\n"); } |
        '(' ')'           { printf("empty\n");     } 
        ;
%%

