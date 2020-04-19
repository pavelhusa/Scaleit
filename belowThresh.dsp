import("stdfaust.lib");

import("libs/threshConfig.lib");

alpha = _;
alphaT = _;

parallelBus = par(i, intervalN, _);

threshSplit = alphaT <: par(i,intervalN, _ * getStepRatio(i));

crossCompare(n) =  ba.selector(n, intervalN) > ba.selector(n, intervalN);

alphaIN = alpha <: parallelBus;

compare = alphaIN, threshSplit <: par(i, intervalN, crossCompare(i) : enableActiveStep(i))
with {
  enableActiveStep(i) = ba.if(i+1 <= activeSteps, _, 0);
};

negate(a) = a <: ma.neg(_) == _ :> _;

invertor = parallelBus <: (par(i, intervalN, ba.if(inv==0, _, 0)), (ro.cross(intervalN) : par(i, intervalN, ba.if(inv==0, 0, negate(_))))) :> parallelBus;

process = compare : invertor;