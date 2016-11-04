#!/bin/sh
touch $1.cpp
touch $1.h

echo "#ifndef $1_h
#define $1_h

class $1
{
  public:
  $1();
};
#endif
" > $1.h

echo " #include \"$1.h\"

" > $1.cpp
