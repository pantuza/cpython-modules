#!/bin/gnuplot

set terminal 'png' size 800,600

set output 'c-module-vs-python-standard-lib.png'

set title 'C module versus Python standard library'

set style histogram errorbars gap 1 lw 2
set style data histograms
set boxwidth 2
set style fill solid

set grid

set yrange [0:*]


plot 'summary_mean.log' using 1:3:xtic('Mean') title 'Mean Python', \
     'summary_mean.log' using 2:4:xtic('Mean') title 'Mean Module'
