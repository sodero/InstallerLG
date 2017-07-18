#ifndef LEXER_H_
#define LEXER_H_

#define LINE yyget_lineno(scanner)

typedef void *yyscan_t;
typedef union
{
    int n; 
    char *s; 
    entry_p e;
} YYSTYPE;

int yyget_lineno(yyscan_t yyscanner);
int yylex(YYSTYPE * yylval_param ,yyscan_t yyscanner);
int yyerror(yyscan_t scanner, char *err);

#endif
