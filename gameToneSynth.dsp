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
    toneSelector(x) = 1 : ba.selectoutn(inputsN, ba.if(conditional(x) == 1, ba.if(inv == 0, x, activeSteps - x), -1));
    conditional(x) = (((x <= 0) & (playBelow == 1)) | ((x >= activeSteps) & (playAbove == 1))) | ((x > 0) & (x < activeSteps));
    toneBank = par(i, inputsN, _ <: envelope, (getFrequency(i) <: synth, tunedNoise :> _) : _ * _);

    getFrequency(x) = ba.if(scaleDown, toFrequencyDown(x), toFrequency(x));
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    toFrequencyDown(n) = ba.midikey2hz(ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n)));
};

process = out :> smoothOutput;