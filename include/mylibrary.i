/* File : mylibrary.i */
%module py_mylibrary

%{
#include "mylibrary.h"
%}

/* Let's just grab the original header file here */
%include "mylibrary.h"