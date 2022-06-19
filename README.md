# Equation-Drawing

## introduction
This is an application of graphic calculator, just like the one in windows 10's accessories(Calculator->graphing).

It is the 3'rd project in the lecture of OOP(Object-oriented programming) in NTUST, which we are asked to create a graphic calculator with GUI.

## features

![image](https://github.com/johnson1205/Equation-Drawing/blob/main/Screenshot%202022-06-18%20105831.png)

## Sample input
- Formula: 2*x
- Formula: sin(x*x+2)
- Formula: a\*x^2+b\*x+c
  - Variable name: a, Variable value: 1
  - Variable name: b, Variable value: 2
  - Variable name: c, Variable value: 3
- etc.

## unimplemented functions 

- variable values with variable names are not supported
  - Variable name: a, Variable value = 1; Variable name: b, Variable value = a/2
- not support the funciton with equal sign because of the design of f(x) = [Function]
- function like tan(x) can't plot correctly
- can't edit any function
- variable name "y" is not allowed since it is the keyword of function

## Prerequisites
Developed in Qt Creator 5.15.2(Community) and builded in MSVC2019.

(QCustomPlot 2.1.0 doesn't support QT versions higher than 6 in 6/18/2022)

## Tools/Plugins in the project
Using following tools/plugins
- [QCustomPlot](https://www.qcustomplot.com/)
  - widget for plotting
- [ExprTK](https://github.com/ArashPartow/exprtk)
  - a powerful toolkit library enable us to strip, identify, and calculate formula

## Contributor

[ME](https://github.com/johnson1205), the owner of this repositories
