# Lab 2 - Improve Ice Breaker

### What is the difference between pass by value, pass by reference, and pass by const reference?

Pass by Value:  
The function gets a copy of the variable, so changing it does not change the original.

Pass by Reference:
The function uses the original variable with `&`, so changes can affect the original.

Pass by Const Reference:
The function uses the original variable with `const &` without copying it, but it cannot change the original.