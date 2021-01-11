#!/bin/bash
date
curl -s "https://forecast.weather.gov/MapClick.php?lat=44.55&lon=-74.939" | grep myforecast-current-lrg | cut -d">" -f2 | cut -d"&" -f1
