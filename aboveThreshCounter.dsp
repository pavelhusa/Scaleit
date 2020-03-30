import("stdfaust.lib");

import("libs/gameConfig.lib");

alpha = _;
alphaT = _;

threshCut = 0.5;
threshSplit = alphaT * threshCut;
aboveThresh = alpha, threshSplit : _ > _;

aboveSamp = ba.sec2samp(holdSec);

// reset = button("gate") : ba.toggle;
counterSamp(x) = ba.if(x >= aboveSamp, 0, x);
// counterSamp(x) = reset;

hold = (+(aboveThresh)~counterSamp) == aboveSamp;

counterReset = ba.if(resetCounter==1, 0, _);
counter = +(hold)~(counterReset);

process = counter;