import("stdfaust.lib");

alpha = _;
alphaT = _;

intervalN = 8;
lowThresh = 0.0;
hiThresh = 0.8;
intervalStep = (hiThresh - lowThresh) / intervalN ;

inv = nentry("invert",0,0,1,1);

parallelBus = par(i, intervalN, _);

threshSplit = alphaT <: par(i,intervalN, _ * (lowThresh + (i * intervalStep)));

crossCompare(n) =  ba.selector(n, intervalN) > ba.selector(n, intervalN);

alphaIN = alpha <: parallelBus;

compare = alphaIN, threshSplit <: par(i, intervalN, crossCompare(i));

negate(a) = a <: ma.neg(_) == _ :> _;

invertor = parallelBus <: (par(i, intervalN, ba.if(inv==0, _, 0)), (ro.cross(intervalN) : par(i, intervalN, ba.if(inv==0, 0, negate(_))))) :> parallelBus;

process = compare : invertor;