import("stdfaust.lib");

import("libs/threshConfig.lib");

alpha = _;
alphaT = _;

parallelBus = par(i, intervalN, _);

threshSplit = alphaT <: par(i,intervalN, _ * getStepRatio(i));

crossSelect(n) = ba.selector(n, intervalN), ba.selector(n, intervalN);

comparator = _ > _;

alphaIN = alpha <: parallelBus;

compare = alphaIN, threshSplit <: par(i, intervalN, crossSelect(i) : comparator)
with {
  enableActiveStep(i) = ba.if(i+1 <= activeSteps, _, 0);
};

negate(a) = a <: ma.neg(_) == _ :> _;

invertor = parallelBus <: unchanged, partCrossed, crossed :> par(i, intervalN, ba.if(i+1 <= activeSteps, _, 0))
with {
  unchanged = par(i, intervalN, ba.if(inv == 0, _, 0));
  partCrossed = par(i, intervalN-2, ro.cross(i+2), si.bus(intervalN-i-2) : par(j, intervalN, negate : ba.if((i+2 == activeSteps) & inv, _, 0)));
  crossed = ro.cross(intervalN) : par(i, intervalN, negate :  ba.if((intervalN == activeSteps) & inv, _, 0));
};

process = compare : invertor;