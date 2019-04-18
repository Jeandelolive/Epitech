#!/usr/bin/python3
from math import *
from sys import *
import sys
import math
import array
import matplotlib.pyplot as plt

def calc_g(tab, period):
    d = tab.__len__() - (period + 1)
    i = d
    result = 0
    tab_result = []
    while (i < tab.__len__()-1):
        if (tab[i+1] > tab[i]):
            tab_result.append(abs(tab[i+1] - tab[i]))
        i = i + 1
    i = 0
    while (i < tab_result.__len__()):
        result = result + tab_result[i]
        i = i + 1
    return (result/period)

def calc_r(tab, period):
    d = tab.__len__() - (period + 1)
    i = d
    result = ((tab[i+period] - tab[i])/tab[i])*100
    return (round(result))

def calc_s(tab, period):
    d = tab.__len__() - period
    i = d
    moy = 0
    result = 0
    while (i < tab.__len__()):
        moy = moy + tab[i]
        i = i + 1
    moy = moy/period
    i = d
    while (i < tab.__len__()):
        result = result + pow((tab[i] - moy), 2)
        i = i + 1
    result = result/period
    result = sqrt(result)
    if (d == 0):
        print ("g=nan\tr=nan%\ts={0}" .format(round(result, 2)))
    return (result)

def loop(tab, period):
    i = 0
    s = 0
    g = 0
    r = 0
    r_tmp = 0
    while (1):
        test = input()
        if (test == "STOP"):
            break
        if (isFloat(test)):
            tab.append(float(test))
        if (i >= period-1):
            s = calc_s(tab, period)
        if (i >= period):
            g = calc_g(tab, period)       
            r = calc_r(tab, period)
            if (r < 0 and r_tmp > 0):
                print ("g={0}\tr={1}%\ts={2}\ta switch occurs" .format(round(g, 2), r, round(s, 2)))
            elif (r > 0 and r_tmp < 0):            
                print ("g={0}\tr={1}%\ts={2}\ta switch occurs" .format(round(g, 2), r, round(s, 2)))
            else:
                print ("g={0}\tr={1}%\ts={2}" .format(round(g, 2), r, round(s, 2)))                    
        if (i < period-1):
            print ("g=nan\tr=nan%\ts=nan")
        r_tmp = r
        i = i + 1

def isFloat(string):
    try:
        float(string)
        return True
    except ValueError:
        return False

def main():
    period = int(sys.argv[1])
    tab = []
    loop(tab, period)
    plt.plot([1,2,3,4])
    plt.ylabel('Label 1')
    plt.show()

main()