import("stdfaust.lib");

alpha = _;
alphaT = _;

intervalN = 12;
lowThresh = 0.8;
hiThresh = 1;
intervalStep = (hiThresh - lowThresh) / intervalN ;

parallelBus = par(i, intervalN, _);

threshSplit = alphaT <: par(i,intervalN, _ * (lowThresh + (i * intervalStep)));

crossCompare(n) =  ba.selector(n, intervalN) > ba.selector(n, intervalN);

alphaIN = alpha <: parallelBus;

compare = alphaIN, threshSplit <: par(i, intervalN, crossCompare(i));

process = compare;