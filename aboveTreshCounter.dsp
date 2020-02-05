import("stdfaust.lib");

import("libs/gameConfig.lib");

alpha = _;
alphaT = _;

treshCut = 0.5;
treshSplit = alphaT * treshCut;
aboveTresh = alpha, treshSplit : _ > _;

aboveSamp = ba.sec2samp(holdSec);

// reset = button("gate") : ba.toggle;
counterSamp(x) = ba.if(x >= aboveSamp, 0, x);
// counterSamp(x) = reset;

hold = (+(aboveTresh)~counterSamp) == aboveSamp;

counter = +(hold)~_;

process = counter;