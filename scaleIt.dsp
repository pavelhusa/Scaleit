//# ScaleIt
// Game Tone and Game Accord combined together to an all-in-one box.
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

gameTone = sumInput <: toneSelector : toneBank
with {
    sumInput = input :> _;
    toneSelector(x) = 1 : ba.selectoutn(inputsN, ba.if(conditional(x) == 1, ba.if(inv == 0, x, activeSteps - x), -1));
    conditional(x) = (((x <= 0) & (playBelow == 1)) | ((x >= activeSteps) & (playAbove == 1))) | ((x > 0) & (x < activeSteps));
    toneBank = par(i, inputsN, _ <: envelope, (getFrequency(i) <: synth, tunedNoise :> _) : _ * _);

    getFrequency(x) = ba.if(scaleDown, toFrequencyDown(x), toFrequency(x));
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    toFrequencyDown(n) = ba.midikey2hz(ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n)));
};

gameAccord = input : par(i, inputsN, _ <: (envelope <: _,_), (toFrequency(i) <: (synth, tunedNoise)) : _,ro.cross(2),_ : par(i, 2, (_*_))) : par(i, inputsN, panorama(i), sp.panner(0.5))
with {
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    panorama(i) = sp.panner(nentry("accordPan%i", 0.5, 0, 1, 0.05));
};
// Parameter gameSelect 0 (default) for gameTone 1 gameAccord.
gameSelector = nentry("gameSelect", 0, 0, 1, 1);

process = compare : invertor <: (gameTone :> _), (gameAccord :> _) : select2(gameSelector) <: par(i, 2, smoothOutput);
