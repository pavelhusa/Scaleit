import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

out = input : par(i, inputsN, toFrequency(i, _) <: synth, tunedNoise)
with {
    toFrequency(n, in) = ba.if(in==1, ba.midikey2hz(baseKeyMIDI+getTone(n)), 0);
};

process = out :> smoothOutput;