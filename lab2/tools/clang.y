%{
    #include <stdio.h>
    #include <stdlib.h>
    extern int yylineno;
    extern FILE * yyin;
    int yylex(void);
    void yyerror(const char *msg);
    int success = 1;
%}
 /* 关键字 */
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE _ALIGNAS _ALIGNOF _ATOMIC _BOOL _COMPLEX _GENERIC _IMAGINARY _NORETURN _STATIC_ASSERT _THREAD_LOCAL __FUNC__
 /* 标识符 */
%token ID 
 /* 常量 */ 
%token INT_CONSTANT FLOAT_CONSTANT CHARACTER STRING
 /* 运算符 */
%token PLUS MINUS STAR DIV MOD INC DEC EQ NE LANGLE RANGLE GE LE NOT AND OR ESPERLUETTE BNOT BOR XOR LS RS DIRECTASSIGN ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN BANDASSIGN XORASSIGN BORASSIGN LSASSIGN RSASSIGN ARROW PERIOD 
 /* 界符 */
%token COMMA ELLIPSIS QUESTION COLON SEMICOLON LPARENTHESE RPARENTHESE LBRACE RBRACE LBRACKET RBRACKET 
%token ERRORCHAR

%nonassoc "then"
%nonassoc ELSE
%define parse.lac full
%define parse.error verbose
 /* 开始符号 */
%start program

%%
program
    : declarations_definitions
    ;

 /* 声明或定义集合 */
declarations_definitions
    : declaration_definition
    | declarations_definitions declaration_definition
    ;

 /* 单个声明或定义 */
declaration_definition
    /* 函数声明或定义 */
    : function_definition
    /* 变量声明或定义 */ 
    | declaration
    ;

function_definition
    : declaration_definition_specifiers declarator block_statement
    | declaration_definition_specifiers declarator declaration_list block_statement
    ;

declaration
    : declaration_definition_specifiers init_declarator_list SEMICOLON
    | declaration_definition_specifiers SEMICOLON
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

declaration_definition_specifiers
    : storage_specifier declaration_definition_specifiers
    | storage_specifier
    | common_type_specifier declaration_definition_specifiers
    | common_type_specifier
    | common_type_qualifier declaration_definition_specifiers
    | common_type_qualifier
    | INLINE declaration_definition_specifiers
    | INLINE
    ;

storage_specifier
    : REGISTER
    | STATIC
    | AUTO
    | EXTERN
    | TYPEDEF
    ;
    
common_type_specifier
    : CHAR
    | DOUBLE
    | FLOAT
    | INT
    | LONG
    | SHORT
    | SIGNED
    | UNSIGNED
    | VOID
    | struct_or_union_specifier
    | enum_specifier
    ;

common_type_qualifier
    : CONST
    | RESTRICT
    | VOLATILE
    ;

struct_or_union_specifier
    : struct_or_union ID LBRACE struct_declaration_list RBRACE
    | struct_or_union LBRACE struct_declaration_list RBRACE
    | struct_or_union ID
    ;

struct_or_union
    : STRUCT
    | UNION
    ;

struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;

init_declarator_list 
    : init_declarator
    | init_declarator_list COMMA init_declarator
    ;

init_declarator
    : declarator
    | declarator DIRECTASSIGN initializer
    ;

struct_declaration
    : common_specifier_qualifier struct_declarator_list SEMICOLON
    | common_specifier_qualifier SEMICOLON
    ;

 /* 常见说明符、限定符 */
common_specifier_qualifier
    : common_type_specifier common_specifier_qualifier
    | common_type_specifier
    | common_type_qualifier common_specifier_qualifier
    | common_type_qualifier
    ;

struct_declarator_list  
    : struct_declarator
    /* COMMA表示',' */
    | struct_declarator_list COMMA struct_declarator
    ;

struct_declarator
    : declarator
    | declarator COLON const_expr
    | COLON const_expr
    ;

enum_specifier
    : ENUM ID LBRACE enumerator_list RBRACE
    /* COMMA表示',' */
    | ENUM ID LBRACE enumerator_list COMMA RBRACE
    | ENUM LBRACE enumerator_list RBRACE
    | ENUM LBRACE enumerator_list COMMA RBRACE
    | ENUM ID
    ;

enumerator_list
    : enumerator
    | enumerator_list COMMA enumerator
    ;

enumerator
    : ID
    /* DIRECTASSIGN表示'=' */
    | ID DIRECTASSIGN const_expr
    ;

declarator
    : pointer bare_declarator
    | bare_declarator
    ;

bare_declarator
    : ID
    /* LPARENTHESE表示'(', RPARENTHESE表示') */
    | LPARENTHESE declarator RPARENTHESE
    /* LBRACKET表示'[', RBRACKET表示']' */
    | bare_declarator LBRACKET RBRACKET
    | bare_declarator LBRACKET STAR RBRACKET
    | bare_declarator LBRACKET common_specifier_qualifier STAR RBRACKET
    | bare_declarator LBRACKET common_specifier_qualifier assign_expr RBRACKET
    | bare_declarator LBRACKET common_specifier_qualifier RBRACKET
    | bare_declarator LBRACKET assign_expr RBRACKET
    | bare_declarator LPARENTHESE param_type_list RPARENTHESE
    | bare_declarator LPARENTHESE id_list RPARENTHESE
    | bare_declarator LPARENTHESE RPARENTHESE
    ;

pointer
    /* STAR表示'*' */
    : STAR common_type_qualifiers
    | STAR
    | STAR common_type_qualifiers pointer
    | STAR pointer
    ;

common_type_qualifiers
    : common_type_qualifier
    | common_type_qualifiers common_type_qualifier
    ;

param_type_list
    : param_list 
    /* ELLIPSIS表示'...' */
    | param_list COMMA ELLIPSIS
    ;

param_list
    : param_declaration
    | param_list COMMA param_declaration
    ;

param_declaration
    : declaration_definition_specifiers declarator
    | declaration_definition_specifiers declarator_without_id
    | declaration_definition_specifiers
    ;

id_list
    : ID
    | id_list COMMA ID 
    ;

initializer
    : assign_expr
    | LBRACE initializer_list RBRACE
    | LBRACE initializer_list COMMA RBRACE
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

type_name
    : common_specifier_qualifier declarator_without_id
    | common_specifier_qualifier
    ;

declarator_without_id
    : pointer
    | pointer bare_declarator_without_id
    | bare_declarator_without_id
    ;

bare_declarator_without_id
    : LPARENTHESE declarator_without_id RPARENTHESE
    | LBRACKET RBRACKET
    | LBRACKET STAR RBRACKET
    | LBRACKET common_specifier_qualifier assign_expr RBRACKET
    | LBRACKET common_specifier_qualifier RBRACKET
    | LBRACKET assign_expr RBRACKET
    | bare_declarator_without_id LBRACKET RBRACKET
    | bare_declarator_without_id LBRACKET STAR RBRACKET
    | bare_declarator_without_id LBRACKET common_specifier_qualifier assign_expr RBRACKET
    | bare_declarator_without_id LBRACKET common_specifier_qualifier RBRACKET
    | bare_declarator_without_id LBRACKET assign_expr RBRACKET
    | bare_declarator_without_id LPARENTHESE param_type_list RPARENTHESE
    | bare_declarator_without_id LPARENTHESE RPARENTHESE
    | LPARENTHESE param_type_list RPARENTHESE
    | LPARENTHESE RPARENTHESE
    ;

statement
    : labeled_statement
    | comma_expr_statement
    | block_statement
    | branch_statement
    | iteration_statement
    | jump_statement
    ;

labeled_statement
    /* COLON表示':' */
    : CASE const_expr COLON statement
    | DEFAULT COLON statement
    | ID COLON statement
    ;

block_statement
    : LBRACE declaration_statement_list RBRACE
    | LBRACE RBRACE
    ;

declaration_statement_list
    : declaration_statement
    | declaration_statement_list declaration_statement
    ;
    
declaration_statement
    : declaration
    | statement
    ;

branch_statement
    : IF LPARENTHESE comma_expr RPARENTHESE statement %prec "then"
    | IF LPARENTHESE comma_expr RPARENTHESE statement ELSE statement 
    | SWITCH LPARENTHESE comma_expr RPARENTHESE statement
    ;

comma_expr_statement
    : SEMICOLON
    | comma_expr SEMICOLON
    ;

iteration_statement
    : FOR LPARENTHESE comma_expr_statement comma_expr_statement comma_expr RPARENTHESE statement
    | FOR LPARENTHESE comma_expr_statement comma_expr_statement RPARENTHESE statement
    | FOR LPARENTHESE declaration comma_expr_statement comma_expr RPARENTHESE statement
    | FOR LPARENTHESE declaration comma_expr_statement RPARENTHESE statement
    | WHILE LPARENTHESE comma_expr RPARENTHESE statement
    | DO statement WHILE LPARENTHESE comma_expr RPARENTHESE SEMICOLON
    ;

jump_statement
    : RETURN comma_expr SEMICOLON
    | RETURN SEMICOLON
    | CONTINUE SEMICOLON
    | BREAK SEMICOLON
    | GOTO ID SEMICOLON
    ;

 /* 包含优先级最低的逗号运算符的表达式 */
comma_expr
    : assign_expr
    | comma_expr COMMA assign_expr
    ;

 /* 包含优先级更低的赋值运算符的表达式 */
assign_expr
    : condition_expr
    /* 一元表达式 赋值运算符 赋值表达式 */
    | unary_expr assign_op assign_expr
    ;

assign_op
    : DIRECTASSIGN
    | ADDASSIGN
    | SUBASSIGN
    | MULASSIGN
    | DIVASSIGN
    | MODASSIGN
    | LSASSIGN
    | RSASSIGN
    | BANDASSIGN
    | BORASSIGN
    | XORASSIGN
    ;

/* 包含优先级更低的条件运算符的表达式 */
condition_expr
    : or_expr
    | or_expr QUESTION comma_expr COLON condition_expr
    ;

const_expr
    : condition_expr
    ;

 /* 包含优先级更低的逻辑或运算符的表达式 */
or_expr
    : and_expr
    | or_expr OR and_expr
    ;

 /* 包含优先级更低的逻辑与运算符的表达式 */
and_expr
    : bor_expr
    | and_expr AND bor_expr
    ;

 /* 包含优先级更低的按位或运算符的表达式 */
bor_expr
    : xor_expr
    | bor_expr BOR xor_expr
    ;

 /* 包含优先级更低的按位异或运算符的表达式 */
xor_expr
    : band_expr
    | xor_expr XOR band_expr
    ;

 /* 包含优先级更低的按位与运算符的表达式 */
band_expr
    : eq_neq_expr
    /* ESPERLUETTE: & */
    | band_expr ESPERLUETTE eq_neq_expr 
    ;

 /* 包含优先级更低的相等和不等关系运算符的表达式 */
eq_neq_expr
    : lt_gt_le_ge_expr
    | eq_neq_expr EQ lt_gt_le_ge_expr
    | eq_neq_expr NE lt_gt_le_ge_expr
    ;

 /* 用可带移位的表达式进一步构建可包含<,>,<=,>=运算符的表达式,因为移位优先级高于这四个关系运算符,这里不包括==和!=因为这两个关系运算符优先级更低*/
lt_gt_le_ge_expr
    : shift_expr
    | lt_gt_le_ge_expr LANGLE shift_expr
    | lt_gt_le_ge_expr RANGLE shift_expr
    | lt_gt_le_ge_expr LE shift_expr
    | lt_gt_le_ge_expr GE shift_expr
    ;

 /* 用加减法表达式进一步构建可包含移位运算符的表达式,因为加减法优先级高于移位*/
shift_expr
    : add_sub_expr
    /* LS表示"<<",RS表示">>" */
    | shift_expr LS add_sub_expr
    | shift_expr RS add_sub_expr
    ;

 /* 用乘除余表达式进一步构建加减法表达式,这样相当于隐式规定了乘除余优先级高于加减法*/
add_sub_expr
    : mult_div_mod_expr
    | add_sub_expr PLUS mult_div_mod_expr
    | add_sub_expr MINUS mult_div_mod_expr
    ;

 /* 可包含 *, /, %的表达式，这三个算术运算符并列齐举是因为*, /, %优先级相同, 简称为乘除余表达式 */
mult_div_mod_expr
    : cast_expr
    | mult_div_mod_expr STAR cast_expr
    | mult_div_mod_expr DIV cast_expr
    | mult_div_mod_expr MOD cast_expr
    ;

cast_expr
    : unary_expr
    | LPARENTHESE type_name RPARENTHESE cast_expr
    ;

 /* 带运算符的表达式 */
 /* 以下所列非终结符代表的表达式集合逐步扩大，即先定义的表达式集是后定义的表达式集的子集，且先定义的表达式集中的运算符优先级更高 */
 /* 包含最高优先级运算符的表达式,优先级最高的运算符都是一元运算符 */
unary_expr
    /* 后缀表达式 */
    : postfix_expr
    | INC unary_expr
    | DEC unary_expr
    | unary_op cast_expr
    | SIZEOF unary_expr
    | SIZEOF LPARENTHESE type_name RPARENTHESE
    ;

unary_op
    /* & */
    : ESPERLUETTE
    /* * */
    | STAR
    /* + */
    | PLUS
    /* - */
    | MINUS
    /* ~ */
    | BNOT
    /* ! */
    | NOT
    ;

 /* 后缀表达式 */
postfix_expr
    : basic_expr
    | postfix_expr INC
    | postfix_expr DEC
    | postfix_expr LBRACKET comma_expr RBRACKET
    | postfix_expr LPARENTHESE RPARENTHESE
    | postfix_expr LPARENTHESE comma_expr RPARENTHESE
    | postfix_expr PERIOD ID    
    | postfix_expr ARROW ID
    | LPARENTHESE type_name RPARENTHESE LBRACE initializer_list RBRACE
    | LPARENTHESE type_name RPARENTHESE LBRACE initializer_list COMMA RBRACE
    ;

 /* 基础表达式 */
basic_expr
    : naive_expr
    | LPARENTHESE comma_expr RPARENTHESE
    ;

 /* 最基本的不带运算符的表达式 */
naive_expr
    : ID
    | INT_CONSTANT
    | FLOAT_CONSTANT
    | CHARACTER
    | STRING
    ;


%% 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: <prog_name> <input_file>\n");
        exit(-1);
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    if (success) {
        printf("Successful Parsing!\n");
    }
    fclose(yyin);
}

void yyerror(const char *msg) {
    fflush(stdout);
    fprintf(stderr, "Failed Parsing\nLine Number: %d %s\n", yylineno, msg);
    success = 0;
}