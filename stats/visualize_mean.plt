#!/bin/gnuplot
reset

set terminal 'png' size 800,600

set output 'mean-c-module-vs-python-standard-lib.png'

set title 'C module versus Python standard library'

set style histogram errorbars gap 1 lw 2
set style data histograms
set boxwidth 1
set style fill solid 1.0 border rgb "black"

set grid

set logscale y
set yrange [0.1:*]


plot 'summary_mean.log' using 1:3:xtic('Mean') title 'Mean Python', \
     'summary_mean.log' using 2:4:xtic('Mean') title 'Mean Module'