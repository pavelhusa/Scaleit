import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

out = input : par(i, inputsN-1, _ <: envelope, (toFrequency(i) <: synth, tunedNoise :> _) : _ * _), lastTone : par(i, inputsN, panorama(i))
with {
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    envelope = en.asr(envTime,1,envTime*2);
    lastTone = _ <: (envelope, os.sawtooth((toFrequency(0) / 4)) : _ * _), (envelope, (toFrequency(inputsN-1) <: synth, tunedNoise :> _) : _ * _) :> _;
    panorama(i) = sp.panner(nentry("accordPan%i", 0.5, 0, 1, 0.05));
};

process = out :> _,_ : par(i, 2, smoothOutput);