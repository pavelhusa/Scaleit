import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");

alpha = _;
alphaT = _;

threshCut = 0.5;
threshSplit = alphaT * threshCut;
aboveThresh = alpha, threshSplit : _ > _;

aboveSamp = ba.sec2samp(holdSec);

counterSamp(x) = ba.if(x >= aboveSamp, 0, x);

hold = (+(aboveThresh)~counterSamp) == aboveSamp;

counterReset = ba.if(resetCounter==1, 0, _);
counter = +(hold)~(counterReset);

limiter(x) = x <: ba.if(x > activeSteps-1, activeSteps-1, _);

process = counter : limiter;