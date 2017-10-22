close all;
clear all;

PWM_level = .2:.1:1;
pred_napelniania = [8.69 39.9 59.52 75.97 89.99 102.46 115.05 128.27 139.79];
p1 = polyfit(PWM_level, pred_napelniania, 3);
load('parametryIdentyfikacja.mat');