//# Game Accord
// Polyphonic version of Game Tone combined with below thresh.
import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

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

out = input : par(i, inputsN, _ <: (envelope <: _,_), (toFrequency(i) <: ((synth, tunedNoise) :> _), bassSynth(i)) : _,ro.cross(2),_ : par(i, 2, (_*_))) : par(i, inputsN, panorama(i), sp.panner(0.5))
with {
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    bassToneConditional(x) = ba.if(x == activeSteps-1, 1, 0);
    bassSynth(x) = ba.if(bassToneConditional(x), subSynth(toFrequency(0)), 0); 
    panorama(i) = sp.panner(nentry("accordPan%i", 0.5, 0, 1, 0.05));
};

process = compare : invertor : out :> _,_ : par(i, 2, smoothOutput);