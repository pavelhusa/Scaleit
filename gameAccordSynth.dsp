import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

out = input : par(i, inputsN, _ <: envelope, (toFrequency(i) <: bassSynth(i), synth, tunedNoise :> _) : _ * _) : par(i, inputsN, panorama(i))
with {
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    envelope = en.asr(envTime,1,envTime*2);
    bassSynth(x) = ba.if(x == (bassTone - 1), os.sawtooth(((toFrequency(0) / 4))), 0); 
    panorama(i) = sp.panner(nentry("accordPan%i", 0.5, 0, 1, 0.05));
};

process = out :> _,_ : par(i, 2, smoothOutput);