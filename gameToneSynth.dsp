//# Game Tone Synth
// Monophonic synth game.
import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

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

process = out :> smoothOutput;