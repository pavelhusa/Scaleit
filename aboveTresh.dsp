import("stdfaust.lib");

alpha = _;
alphaT = _;

intervalN = 4;
lowTresh = 0.8;
hiTresh = 1;
intervalStep = (hiTresh - lowTresh) / intervalN ;

parallelBus = par(i, intervalN, _);

treshSplit = alphaT <: par(i,intervalN, _ * (lowTresh + (i * intervalStep)));

crossCompare(n) =  ba.selector(n, intervalN) > ba.selector(n, intervalN);

alphaIN = alpha <: parallelBus;

compare = alphaIN, treshSplit <: par(i, intervalN, crossCompare(i));

process = compare;