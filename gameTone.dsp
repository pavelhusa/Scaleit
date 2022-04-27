//# Game Tone
// Monophonic synth game combined with belowThresh.
import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

alpha = _;
alphaT = _;

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

out = sumInput <: toneSelector : toneBank
with {
    sumInput = input :> _;
    toneSelector(x) = exclusiveConditional : ba.selectoutn(inputsN, ba.if(inv == 0, (x + (excl : int)), ((activeSteps - x) + (excl : int)))) : par(i, inputsN, _);
    exclusiveConditional(x) = ba.if(((x == 0) & (excl == 1)), 0, 1);
    toneBank = par(i, inputsN, _ <: envelope, (getFrequency(i-(excl : int)) <: synth, tunedNoise :> _) : _ * _);

    getFrequency(x) = ba.if(scaleDown, toFrequencyDown(x), toFrequency(x));
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    toFrequencyDown(n) = ba.midikey2hz(ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n)));
};

process = compare : invertor : out :> smoothOutput;