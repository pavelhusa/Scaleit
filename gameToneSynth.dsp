import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

out = inputExclusive <: toneTransform :  par(i, inputsN, _ <: envelope, (getFrequency(i) <: synth, tunedNoise :> _) : _ * _)
with {
    inputExclusive = par(i, inputsN, ba.if((excl == 0) & (i == 0) & (inv == 0), 1, _));
    toneTransform = par(i, inputsN, _) <: (par(i, inputsN, _) , (!, par(i, inputsN-1, _): par(i, inputsN-1, _), 0)) <: par(i, inputsN, crossCompare(i));
    crossCompare(n) =  ba.selector(n, inputsN) != ba.selector(n, inputsN);
    getFrequency(x) = ba.if(scaleDown, toFrequencyDown(x), toFrequency(x));
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    toFrequencyDown(n) = ba.midikey2hz(ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n)));
};

process = out :> smoothOutput;