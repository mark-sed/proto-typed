flex --header-file=frontend/lexer.hpp -o frontend/lexer.cpp frontend/lexer.ll
bison frontend/parser.yy -o frontend/parser.cpp
