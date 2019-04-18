#!/usr/bin/python3
from math import *
from sys import *
import sys
import math
import array

def getDataFromFile():
    file_obj = open("indexes.txt", "r")
    return (file_obj.readlines())

def doAverage(tab):
    result = 0.0
    j = 0
    for i in range(len(tab)):
        result = result + float(tab[i])
        j = j + 1
    result = result / j
    return (result)

def doSMA(tab):
    i = 0
    result_tab = []

    result_tab.append(float(tab[0]))
    while i+2 < len(tab):
        result_tab.append((float(tab[i]) + float(tab[i + 1]) + float(tab[i + 2]))/3)
        i = i + 1
    result_tab.append(float(tab[len(tab)-1]))
    return (result_tab)

def main():
    tab = getDataFromFile()
    print (doAverage(tab))
    print (doSMA(tab))

main()