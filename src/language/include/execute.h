#ifndef EXECUTE_H
#define EXECUTE_H

#include "ast.h"
#include "symbol_table.h"

symbol execute_symbol(ast head, symbol_table st);

#endif
