//# Game Tone
// Monophonic synth game combined with belowThresh.
import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

gameTone = input :> toneSelector <: par(i, inputsN, envelope, (getFrequency(i) <: synth, tunedNoise :> _) : _ * _) :> _,_ : par(i, 2, smoothOutput * gameToneON)
with {
    toneSelector(x) =  _ <: ba.selectoutn(inputsN, ba.if(inv == 0, x, (activeSteps - x))) : par(i, inputsN, _);
    getFrequency(x) = ba.if(scaleDown, toFrequencyDown(x), toFrequency(x));
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    toFrequencyDown(n) = ba.midikey2hz(ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n)));
};
