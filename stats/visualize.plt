#!/bin/gnuplot

set terminal 'png' size 800,600

set output 'c-module-vs-python-standard-lib.png'

set title 'C module versus Python standard library'

set style data histogram
set boxwidth 2
set style fill solid

set grid

set yrange [0:7000]


plot 'summary_mean.log' using 1:xtic('Mean')  title 'Mean Python', \
     'summary_mean.log' using 2 title 'Mean Module'
