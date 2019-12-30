1. gcc warning flags which should be turned on for new projects:

-Wall

-Wextra # reasonable and standard

-Wshadow # warn the user if a variable declaration shadows one from a
         # parent context
         
-Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                   # non-virtual destructor.
                   
-Wold-style-cast # warn for c-style casts

-Wcast-align # warn for potential performance problem casts

-Wunused # warn on anything being unused

-Woverloaded-virtual # warn if you overload (not override) a virtual func

-Wpedantic # warn if non-standard C++ is used

-Wconversion # warn on type conversions that may lose data

-Wsign-conversion # warn on sign conversions

-Wnull-dereference # warn if a null dereference is detected

-Wdouble-promotion # warn if float is implicit promoted to double

-Wformat=2 # warn on security issues around functions that format output
           # (ie printf)

-Wduplicated-cond # warn if if / else chain has duplicated conditions

-Wduplicated-branches # warn if if / else branches have duplicated code

-Wlogical-op # warn about logical operations being used where bitwise were probably wanted

-Wuseless-cast # warn if you perform a cast to the same type

-Wlifetime # ///

2. nm to show shared lib functions:

nm -gmU libfoo.so | c++filt
