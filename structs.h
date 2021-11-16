#pragma once

typedef enum { v_void, v_int, v_float, v_bool, v_string } v_type;

// function parameter declaration node
typedef struct _param_dec {
    v_type typespec;
    char* id;
    struct _param_dec* next;
} param_dec;

typedef struct _func_body {

} func_body;

// function header node
typedef struct _func_header {
    char* id;
    v_type typespec;
    param_dec* param;
} func_header;

typedef struct _func_dec {
    char* id;
    v_type return_type;
} func_dec;

/*
// function declaration node
typedef struct _func_dec {
    func_header* f_header;
    func_body* f_body;
} func_dec;
*/

typedef struct {
    v_type typespec;
    char* id;
} var_dec;

typedef enum { d_var, d_func } d_type;

typedef struct _dec_node {
    d_type type;
    union {
        func_dec* func;
        var_dec* var;
    } dec;
    struct _dec_node* next;
} dec_node;

typedef struct _prog_node {
    dec_node* dlist;
} prog_node;
